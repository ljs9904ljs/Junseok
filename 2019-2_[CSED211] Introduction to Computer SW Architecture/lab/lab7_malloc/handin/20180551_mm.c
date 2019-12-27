/*
 * 20180551 컴퓨터공학과
 * 이준석  ( Junseok Lee )
 * POVIS ID : ljs9904ljs
 */

 /* segregated free list로 구현한다.
  * segregated free list는 void * free_lists[LIST]라는 이름으로 선언되었으며
  * implicit free list들을 배열의 한 칸에 가지고 있다.
  * 그래서 header와 footer가 동시에 필요하다. 
  * 8바이트 alignment 조건 하에서는 header의 하위 3개의 비트가 '항상' 0이다.
  * 그래서 하위 3개의 비트를 다양하게 이용할 수 있는데, 본인은 최하위 비트(LSB)를 allocated bit로 사용하였고
  * 바로 다음 비트(2^1 자리 비트)를 tag bit로 사용하였다. 
  *
  * mm_check 함수는 heap consistency check를 위한 함수이다. 자세한 설명은 해당 함수의 정의 부분에 주석으로 작성하였다.
  */
 
 /*
   if (p == (void *)-1)
	return NULL;
 이것은 힙 메모리 사이즈 자체가 부족함을 의미한다.
 
 */
 
 // header와 footer가 각각 4바이트씩이므로
 // 0보다 큰 크기를 할당하려고 시도할 때 9바이트 이상이 할당되게 된다. 그리고
 // alignment를 맞춰야하므로 최소 크기는 16바이트부터 시작한다.
 // alignment가 8바이트이기 때문이다.
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)


#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))


/* 상수 정의 */
#define WORD     4          
#define DWORD     8          
#define LIST    20  
#define INITCHUNKSIZE (1<<6)
#define CHUNKSIZE (1<<12) 
#define REALLOC_BUFFER  (1<<7)    
/* 상수 정의 끝 */

// 크기 비교를 위한 매크로 함수들
#define MAX(x, y) ((x) > (y) ? (x) : (y)) 
#define MIN(x, y) ((x) < (y) ? (x) : (y)) 

// 블록 크기랑 allocated bit를 묶는다
#define MAKE_HEADER(size, alloc) ((size) | (alloc))

// p라는 주소값에 대해 읽는 것과 쓰는 것 
#define GET(p)            (*(unsigned int *)(p))
#define WRITE_WITH_TAG(p, val)       (*(unsigned int *)(p) = (val) | GET_TAG(p))
#define WRITE_WO_TAG(p, val) (*(unsigned int *)(p) = (val))

//predecessor인 블록이랑 successor인 블록에 대한 포인터를 저장한다. 
#define SET_PTR(p, ptr) (*(unsigned int *)(p) = (unsigned int)(ptr))

// 블록 크기, allocated bit, reallocated bit를 읽고 기록한다. 
#define GET_SIZE(p)  (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)
#define GET_TAG(p)   (GET(p) & 0x2)
#define SET_RATAG(p)   (GET(p) |= 0x2)
#define REMOVE_RATAG(p) (GET(p) &= ~0x2)

// ptr에 대해서 header와 footer의 주소를 구한다.
#define HEAD_PTR(ptr) ((char *)(ptr) - WORD)
#define FOOT_PTR(ptr) ((char *)(ptr) + GET_SIZE(HEAD_PTR(ptr)) - DWORD)

// 다음 블록과 이전 블록의 주소를 구한다.
#define NEXT_BLKP(ptr) ((char *)(ptr) + GET_SIZE((char *)(ptr) - WORD))
#define PREV_BLKP(ptr) ((char *)(ptr) - GET_SIZE((char *)(ptr) - DWORD))

// free list에서 predecessor인 블록이랑 successor인 블록을 구한다.
#define PRED_PTR(ptr) ((char *)(ptr))
#define SUCC_PTR(ptr) ((char *)(ptr) + WORD)

// segregated list 상에서 free block의 predecessor 혹은 successor를 구한다.
#define PRED(ptr) (*(char **)(ptr))
#define SUCC(ptr) (*(char **)(SUCC_PTR(ptr)))

/* mm_check를 위한 매크로 */
#define CHECK         0 /* Kill bit: Set to 0 to disable checking
                           (Checking is currently disabled through comments) */
#define CHECK_MALLOC  1 /* Check allocation operations */
#define CHECK_FREE    1 /* Check free operations */
#define CHECK_REALLOC 1 /* Check reallocation operations */
#define DISPLAY_BLOCK 1 /* Describe blocks in heap after each check */
#define DISPLAY_LIST  1 /* Describe free blocks in lists after each check */
#define PAUSE         1 /* Pause after each check, also enables the function to
                           skip displaying mm_check messages*/                           
#define LINE_OFFSET   4 /* Line offset for referencing trace files */


/* global variable들의 선언 */
// segregated free list
void *free_lists[LIST];

// mm_check를 위한 변수들 
char *prologue_block;
int line_count; // Running count of operations performed
int skip;       // Number of operations to skip displaying mm_check messages
/* global variable들의 선언 끝 */


/* 사용자 정의 함수 */
// 1. 힙 자체의 크기를 size만큼 늘린다.
static void *extend_heap(size_t size);

// 2. segregated free list에 node를 추가한다.
static void insert_node(void *ptr, size_t size);

// 3. segregated free list에서 node를 제거한다.
static void delete_node(void *ptr);

// 4. free block들 간의 coalescing
static void *coalesce(void *ptr);

// 5. 할당할 때 할당된 블록을 어디에 놓을지, 그리고 split을 할지 말지를 정한다.
static void *place(void *ptr, size_t asize);

// heap consistency checker 기능을 수행하는 함수이다.
void mm_check(char caller, void* caller_ptr, int caller_size);
/* 사용자 정의 함수 끝 */


// 1. 힙 메모리 자체의 크기를 늘리는 함수이다. size만큼 늘린다.
static void *extend_heap(size_t size)
{
    size_t tmp=size;
    void * ptr= mem_sbrk(tmp);

    // 힙 자체의 공간을 더 이상 늘릴 수 없다면,
    if(ptr == (void * ) -1)
        return NULL;

	// header와 footer를 설정한다. 둘은 똑같다.
    WRITE_WO_TAG(HEAD_PTR(ptr),MAKE_HEADER(tmp,0));
    WRITE_WO_TAG(FOOT_PTR(ptr),MAKE_HEADER(tmp,0));
	
	// 이렇게 해야 힙 메모리가 할당되고 coalescing할 때 메모리 침범을 하지 않는다.
    WRITE_WO_TAG(HEAD_PTR(NEXT_BLKP(ptr)),MAKE_HEADER(0,1));
    
	// 새로 만들어진 free block을 segregated free list에 추가한다.
    insert_node(ptr,tmp);

    return coalesce(ptr);
}

// 2. segregated free list에 노드를 추가한다.
static void insert_node(void * ptr, size_t size)
{
    int index;
    void *next = ptr;
    void *before = NULL;

    for(index=0;index < LIST -1; index++ )
    {
        if(size > 1)
        {
            size = size >> 1;
        }
        else break;
    }
    next = free_lists[index];
	
	// 올바른 size class에 대한 free list에 추가되어야 하므로
	// 적절한 크기를 찾을 때까지 순회한다.
    while( next !=NULL && size < GET_SIZE(HEAD_PTR(next)))
    {
        before = next;
        next = PRED(next);
    }
    if(next != NULL)
    {
        // free list의 중간에 추가할 때
        if(before!= NULL)
        {
            SET_PTR(PRED_PTR(ptr),next);
            SET_PTR(SUCC_PTR(next), ptr);
            SET_PTR(PRED_PTR(before), ptr);
            SET_PTR(SUCC_PTR(ptr), before);
        }
        // free list의 처음에 추가할 때
        else
        {
            SET_PTR(PRED_PTR(ptr), next);
            SET_PTR(SUCC_PTR(next), ptr);
            SET_PTR(SUCC_PTR(ptr), NULL);
			
            // 처음 부분에 추가하였으므로 free list 상에서 가장 앞에 위치하게 된다.
            free_lists[index]= ptr;
        }
    }
   
    else
    {
        // free list의 마지막에 추가할 때
        if(before!=NULL)
        {
            SET_PTR(PRED_PTR(ptr),NULL);
            SET_PTR(SUCC_PTR(ptr), before);
            SET_PTR(PRED_PTR(before),ptr);
        }
        // free list가 처음에 비어있는 상태라면
        else
        {
            SET_PTR(PRED_PTR(ptr),NULL);
            SET_PTR(SUCC_PTR(ptr),NULL);
			
            // 마찬가지로 free list 상에서 가장 앞에 위치하게 된다.
            free_lists[index]=ptr;
        }
    }
    return;
    
}

// 3. segregated free list에서 노드를 제거한다.
static void delete_node(void * ptr)
{
    int index;
    int size= GET_SIZE(HEAD_PTR(ptr));

    // segregated free list의 index를 순회하면서 찾는다.
    while((index < LIST-1  ) && (size >1) )
    {
        size = size >>1;
        index++;
    }

    // 제거할 것이 segregated free list의 시작 부분이 아닌 경우에
    if(PRED(ptr) != NULL)
    {
        // 제거할 것이 segregated free list의 마지막 부분이 아닌 경우에
        if(SUCC(ptr) != NULL)
        {
            // 제거할 것의 앞과 뒤의 노드들을 연결한다.
            SET_PTR(SUCC_PTR(PRED(ptr)) , SUCC(ptr));
            SET_PTR(PRED_PTR(SUCC(ptr)) , PRED(ptr));
        }
		
        // 제거할 것이 segregated free list의 마지막 부분인 경우에
        else
        {
			// 제거할 것의 이전 노드의 다음 노드가 NULL이도록 한다.
            SET_PTR(SUCC_PTR(PRED(ptr)), NULL);
            free_lists[index] = PRED(ptr);
        }
    }
    
	// 제거할 것이 segregated free list의 시작 부분인 경우에
    else
    {
        
        if(SUCC(ptr) !=NULL)
        {
			// 시작의 이전 노드는 NULL 이므로
            SET_PTR(PRED_PTR(SUCC(ptr)),NULL);
        }
        else
        {
			// 다음 노드가 없는 경우에, 즉 하나만 남아있던 것인데 그 남은 하나가 제거되는 것이므로
            free_lists[index]=NULL;
        }
    }
    return;
}

// 4. coalescing을 하는 함수이다.
static void * coalesce(void * ptr)
{
    // coalescing은 이전과 다음을 살펴서 free block이라면 합치는 과정이다. 
	// 그러기 위해서 이전 블록과 다음 블록의 할당 유무 정보가 필요하다.
    size_t prev_all =GET_ALLOC(HEAD_PTR(PREV_BLKP(ptr)));
    
    size_t next_all =GET_ALLOC(HEAD_PTR(NEXT_BLKP(ptr)));
    size_t size =GET_SIZE(HEAD_PTR(ptr));

   // 이전 블록이 재할당되어있으면 할당되어있는 것이므로 합병을 안한다.
    if(GET_TAG(HEAD_PTR(PREV_BLKP(ptr))) == 1)
        prev_all = 1;

    // 이전과 다음이 할당되어있다면 합병 안함.
    if(prev_all == 1 && next_all ==1)
        return ptr;

    // 현재와 다음의 합병
    if(prev_all == 1 && next_all == 0)
    {
        delete_node(ptr);
        delete_node(NEXT_BLKP(ptr));
		
        // 새로운 블록의 크기는 (현재 블록 + 다음 블록)과 같다
        size += GET_SIZE(HEAD_PTR(NEXT_BLKP(ptr)));
		
        // header와 footer를 달아준다.
        WRITE_WITH_TAG(HEAD_PTR(ptr), MAKE_HEADER(size,0));
        WRITE_WITH_TAG(FOOT_PTR(ptr), MAKE_HEADER(size,0));
    }
    // 이전과 현재의 합병
    else if(prev_all == 0 && next_all == 1)
    {
        delete_node(ptr);
        delete_node(PREV_BLKP(ptr));
		
		// 새로운 블록의 크기는 (이전 블록 + 현재 블록)과 같다.
        size+= GET_SIZE(HEAD_PTR(PREV_BLKP(ptr)));
        ptr= PREV_BLKP(ptr); // 이전 블록을 기준으로 합병되어야 한다.
		
		//header와 footer를 달아준다.
        WRITE_WITH_TAG(HEAD_PTR(ptr), MAKE_HEADER(size,0));
        WRITE_WITH_TAG(FOOT_PTR(ptr), MAKE_HEADER(size,0));
    }
    // 이전과 현재와 다음의 합병
    else if (prev_all ==0 && next_all ==0)
    {
        delete_node(ptr);
        delete_node(PREV_BLKP(ptr));
        delete_node(NEXT_BLKP(ptr));

		// 새로운 블록의 크기는 (이전 블록 + 현재 블록 + 다음 블록)과 같다.
        size+= GET_SIZE(HEAD_PTR(PREV_BLKP(ptr))) + GET_SIZE(HEAD_PTR(NEXT_BLKP(ptr)));

		// 이 경우에도 이전 블록을 기준으로 합병해야 한다.
        ptr = PREV_BLKP(ptr);
		
		// header와 footer를 달아준다.
        WRITE_WITH_TAG(HEAD_PTR(ptr), MAKE_HEADER(size,0));
        WRITE_WITH_TAG(FOOT_PTR(ptr), MAKE_HEADER(size,0));   
    }
	
    // free block을 segregated free list에 추가하고 주소를 반환한다.
    insert_node(ptr,size);
    return ptr;
}


// 5. 할당하려는 블록의 위치를 정하기 위한 함수이다. 즉, 할당을 한다.
// free block을 쪼개는 과정도 필요하다면 수행한다.
static void * place(void * ptr, size_t asize)
{
    size_t size = GET_SIZE(HEAD_PTR(ptr));
    size_t remain = size - asize; // 할당하고 남은 여분의 free block

    delete_node(ptr);

    if(remain <= DWORD*2)
    {
        // 여분의 free block이 
		// 블록의 최소 크기 조건(16바이트 == DWORD * 2)보다도 작다면 split을 하지 않는다.
        WRITE_WITH_TAG(HEAD_PTR(ptr), MAKE_HEADER(size,1));
        WRITE_WITH_TAG(FOOT_PTR(ptr), MAKE_HEADER(size,1));
    }

    else if(asize >= 100)
    {
        // free block을 쪼갠다.
		//--------------------------------------------------------------
		//            (current)            (next)
		// list : [쪼개진 free block] -> [allocated block]
		// 
		// 의 모양으로 할당한다.
		//--------------------------------------------------------------
		
		//[쪼개진 free block]
        WRITE_WITH_TAG(HEAD_PTR(ptr), MAKE_HEADER(remain,0));
        WRITE_WITH_TAG(FOOT_PTR(ptr), MAKE_HEADER(remain,0));
        
		//[allocated block]
        WRITE_WO_TAG(HEAD_PTR(NEXT_BLKP(ptr)), MAKE_HEADER(asize,1));
        WRITE_WO_TAG(FOOT_PTR(NEXT_BLKP(ptr)), MAKE_HEADER(asize,1));
		
        //여분의 free block을 segregated free list에 넣어 준다.
        insert_node(ptr,remain);
		
		//할당이 된 것은 next block 이므로 그것을 반환한다.
        return NEXT_BLKP(ptr);
    }
    else
    {
		// free block을 쪼갠다.
		//--------------------------------------------------------------
		//            (current)            (next)
		// list : [allocated block] -> [쪼개진 free block]
		// 
		// 의 모양으로 할당한다.
		//--------------------------------------------------------------
		
		//[allocated block]
        WRITE_WITH_TAG(HEAD_PTR(ptr), MAKE_HEADER(asize,1));
        WRITE_WITH_TAG(FOOT_PTR(ptr), MAKE_HEADER(asize,1));
		
		//[쪼개진 free block]
        WRITE_WO_TAG(HEAD_PTR(NEXT_BLKP(ptr)), MAKE_HEADER(remain,0));
        WRITE_WO_TAG(FOOT_PTR(NEXT_BLKP(ptr)), MAKE_HEADER(remain,0));
		
		//여분의 free block을 segregated free list에 넣는다.
        insert_node(NEXT_BLKP(ptr),remain);
    }
    return ptr;
}
/* 
 * mm_init - initialize the malloc MAKE_HEADERage.
 */
int mm_init(void)
{
    int index;
	char * heap;
	
    //free list가 처음에는 NULL이다.
    for(index=0;index< LIST; index++)
        free_lists[index] = NULL;

    
    // 최소 크기조차도 힙을 늘릴 수 없다면 할당을 할 수가 없다.
    if((long)(heap = mem_sbrk(4 * WORD)) == -1)
        return  -1;
    
    WRITE_WO_TAG(heap, 0); //padding    
    WRITE_WO_TAG(heap + 1* WORD, MAKE_HEADER(DWORD,1)); //prologue header    
    WRITE_WO_TAG(heap + 2* WORD, MAKE_HEADER(DWORD,1)); //prologue footer
    WRITE_WO_TAG(heap + 3* WORD, MAKE_HEADER(0,1)); //epilogue header

	//heap consistency check를 위한 것들
	//prologue_block = heap + DWORD;
	
	
    if(extend_heap(INITCHUNKSIZE)==NULL)
        return -1;
	
	
	//heap consistency check를 위한 것들
	//line_count = LINE_OFFSET;
	//skip = 0;
	
    return 0;
}

/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
    if(size==0)
        return NULL;

    size_t asize ; //adjust size
    size_t extend; //필요에 따라 힙을 늘려야 한다.
    void * ptr = NULL;

    // header와 footer를 위해 총 DWORD 만큼이 필요하다.
    if( size <= DWORD)
    {
        asize = 2*DWORD;
    }
    else
    {
        asize =ALIGN(size + DWORD);
    }

    int index=0;
    size_t search =asize;
    // segregated free list에 대한 순회
    while(index < LIST)
    {
        //적절한 free list을 찾았다.
        if((index == LIST -1) || (search <= 1 && free_lists[index] != NULL))
        {
            ptr = free_lists[index];
			
            // free block이 없으면 안되고,
			// 할당하려는 것보다 free block의 크기가 작으면 안되고,
			// 재할당되어있으면 넘어간다.
            while(ptr !=NULL  && ((asize > GET_SIZE(HEAD_PTR(ptr)) || GET_TAG(ptr))))
            {
                ptr = PRED(ptr);
            }
            //can find the free block
            if(ptr != NULL)
                break;
        }
        search = search >>1;
        index ++;
    }
    // heap 공간이 부족한 경우에, heap을 늘려준다.
    if(ptr == NULL)
    {
        extend = MAX(asize,CHUNKSIZE);
		
        // 힙을 더이상 늘릴 수 없다면
        ptr = extend_heap(extend);
        if(ptr == NULL)
            return NULL;
    }
	
    // free list들 중에서 적절한 위치를 찾아 할당한다.
    ptr = place(ptr,asize);
	
	//mm_check('a', ptr, GET_SIZE(ptr));
	
    return ptr;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr)
{
    size_t size= GET_SIZE(HEAD_PTR(ptr));
    //reallcoted tag 제거
    REMOVE_RATAG(HEAD_PTR(NEXT_BLKP(ptr)));
    
	//header와 footer를 할당 안 된 상태로( 0 ) 바꿔준다.
    WRITE_WITH_TAG(HEAD_PTR(ptr), MAKE_HEADER(size,0));
    WRITE_WITH_TAG(FOOT_PTR(ptr), MAKE_HEADER(size,0));
	
    //새로 생긴 free block을 segregated free list에 넣어준다.
    insert_node(ptr,size);
	
    //새로 생긴 free block과 관련하여 coalescing을 해준다.
    coalesce(ptr);

	//mm_check('f', ptr, GET_SIZE(ptr));
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
    if(size == 0 )
        return NULL;
    void * oldptr = ptr;
    size_t neWORD =size; //new block의 size
    int remain; // 할당 후 남은 크기
    int extend; // heap을 얼마나 증가시킬 것인가?
    int blockbuff;

    // alignment requirement에 의해 최소 크기는 16바이트이다.
    if( size <= DWORD)
    {
        neWORD = 2*DWORD;
		// payload 크기에 header랑 footer 크기를 더한 값이다.
    }
    else
    {
        neWORD =ALIGN(size + DWORD);
    }
    //블록 크기에 대한 overhead requirment를 더한다.
    neWORD += REALLOC_BUFFER;
    //block buffer 계산
    blockbuff = GET_SIZE(HEAD_PTR(ptr)) - neWORD;
    // heap 공간이 부족하면
    if(blockbuff < 0)
    {
        // 재할당할 크기가 기존보다 크고 다음 블록이 free block이라면
		// 다음 블록을 재할당하는 것에 이용한다.
        if(GET_ALLOC(HEAD_PTR(NEXT_BLKP(ptr)))==0 || GET_SIZE(HEAD_PTR(NEXT_BLKP(ptr))) == 0)
        {
            
            remain = GET_SIZE(HEAD_PTR(ptr)) + GET_SIZE(HEAD_PTR(NEXT_BLKP(ptr))) - neWORD;
            
			// 재할당할 공간이 모자라다면 힙을 추가로 늘린다.
            if(remain < 0) 
            {
                extend = MAX ( -remain, CHUNKSIZE);
                
				//heap을 더이상 늘릴 수 없다면
                if(extend_heap(extend) == NULL)
                    return NULL;
                remain += extend;
            }

			//segregated free list에서 해당 노드를 제거하고
            delete_node(NEXT_BLKP(ptr));

            //그 공간에 새로운 할당(재할당)을 수행한다.
            WRITE_WO_TAG(HEAD_PTR(ptr), MAKE_HEADER(neWORD + remain,1));
            WRITE_WO_TAG(FOOT_PTR(ptr), MAKE_HEADER(neWORD + remain,1));

        }
        else
        {
        // 다음 블록이 할당이 이미 되어있는 블록이다.
		// 새로운 free block을 찾아야한다.
		// 재할당하고 나서 기존에 저장되어 있던 데이터를 옮겨적는다.
            oldptr = mm_malloc(neWORD -DWORD);
            memcpy( oldptr, ptr, MIN(size,neWORD));
            mm_free(ptr);
        }
        blockbuff = GET_SIZE(HEAD_PTR(oldptr)) - neWORD;
    }

    if(blockbuff < 2 * REALLOC_BUFFER)
    {
        SET_RATAG(HEAD_PTR(NEXT_BLKP(oldptr)));
    }
    //return the reallocation block
	
	//mm_check('r', oldptr, GET_SIZE(oldptr));
    return oldptr;
}

/*
 * mm_check는 heap consistency checker이다.
 * 메모리 연산에 관한 정보를 보여준다.
 * 모든 블록들과 free list들에 대해 출력한다.
 * header와 footer가 같은지도 확인한다.
 * free block이 옳바른 list 안에 들어가 있는지도 확인한다.
 * 일시정지 가능, check를 건너뛰는 것도 가능.
 */

/*
void mm_check(char caller, void* caller_ptr, int caller_size)
{
  int size;  // Size of block
  int alloc; // Allocation bit
  char *ptr = prologue_block + DWORD;
  int block_count = 1;
  int count_size;
  int count_list;
  int loc;   // Location of block relative to first block
  int caller_loc = (char *)caller_ptr - ptr;
  int list;
  char *scan_ptr;
  char skip_input;
  
  if (!skip)
    printf("\n[%d] %c %d %d: Checking heap...\n",
      line_count, caller, caller_size, caller_loc);
  
  while (1) {
    loc = ptr - prologue_block - DWORD;
    
    size = GET_SIZE(HEAD_PTR(ptr));
    if (size == 0)
      break;
    
    alloc = GET_ALLOC(HEAD_PTR(ptr));
    
    // Print block information
    if (DISPLAY_BLOCK && !skip) {
      printf("%d: Block at location %d has size %d and allocation %d\n",
        block_count, loc, size, alloc);
      if (GET_TAG(HEAD_PTR(ptr))) {
        printf("%d: Block at location %d is tagged\n",
          block_count, loc);
      }
    }
    
    // Check consistency of size and allocation in header and footer
    if (size != GET_SIZE(FOOT_PTR(ptr))) {
      printf("%d: Header size of %d does not match footer size of %d\n",
        block_count, size, GET_SIZE(FOOT_PTR(ptr)));
    }
    if (alloc != GET_ALLOC(FOOT_PTR(ptr))) {
      printf("%d: Header allocation of %d does not match footer allocation "
        "of %d\n", block_count, alloc, GET_ALLOC(FOOT_PTR(ptr)));
    }
    
    // Check if free block is in the appropriate list
    if (!alloc) {
      // Select segregated list
      list = 0;
      count_size = size;
      while ((list < LIST - 1) && (count_size > 1)) {
        count_size >>= 1;
        list++;
      }
      
      // Check list for free block
      scan_ptr = free_lists[list];
      while ((scan_ptr != NULL) && (scan_ptr != ptr)) {
        scan_ptr = PRED(scan_ptr);
      }
      if (scan_ptr == NULL) {
        printf("%d: Free block of size %d is not in list index %d\n",
          block_count, size, list);
      }
    }
    
    ptr = NEXT_BLKP(ptr);
    block_count++;
  }
  
  if (!skip)
    printf("[%d] %c %d %d: Checking lists...\n",
      line_count, caller, caller_size, caller_loc);
  
  // Check every list of free blocks for validity
  for (list = 0; list < LIST; list++) {
    ptr = free_lists[list];
    block_count = 1;
    
    while (ptr != NULL) {
      loc = ptr - prologue_block - DWORD;
      size = GET_SIZE(HEAD_PTR(ptr));
      
      // Print free block information
      if (DISPLAY_LIST && !skip) {
        printf("%d %d: Free block at location %d has size %d\n",
          list, block_count, loc, size);
        if (GET_TAG(HEAD_PTR(ptr))) {
          printf("%d %d: Block at location %d is tagged\n",
            list, block_count, loc);
        }
      }
      
      // Check if free block is in the appropriate list
      count_list = 0;
      count_size = size;
      
      while ((count_list < LIST - 1) && (count_size > 1)) {
        count_size >>= 1;
        count_list++;
      }
      if (list != count_list) {
        printf("%d: Free block of size %d is in list %d instead of %d\n",
          loc, size, list, count_list);
      }
      
      // Check validity of allocation bit in header and footer
      if (GET_ALLOC(HEAD_PTR(ptr)) != 0) {
        printf("%d: Free block has an invalid header allocation of %d\n",
          loc, GET_ALLOC(FOOT_PTR(ptr)));
      }
      if (GET_ALLOC(FOOT_PTR(ptr)) != 0) {
        printf("%d: Free block has an invalid footer allocation of %d\n",
          loc, GET_ALLOC(FOOT_PTR(ptr)));
      }
      
      ptr = PRED(ptr);
      block_count++;
    }
  }
  
  if (!skip)
    printf("[%d] %c %d %d: Finished check\n\n",
      line_count, caller, caller_size, caller_loc);
  
  // Pause and skip function, toggled by PAUSE preprocessor directive. Skip
  // allows checker to stop pausing and printing for a number of operations.
  // However, scans are still completed and errors will still be printed.
  if (PAUSE && !skip) {
    printf("Enter number of operations to skip or press <ENTER> to continue.\n");
    
    while ((skip_input = getchar()) != '\n') {
      if ((skip_input >= '0') && (skip_input <= '9')) {
        skip = skip * 10 + (skip_input - '0');
      }
    }
    
    if (skip)
      printf("Skipping %d operations...\n", skip);
      
  } else if (PAUSE && skip) {
    skip--;
  }
  
  return;
}
*/