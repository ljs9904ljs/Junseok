/*
*  학번: 20180551
*  학과: 컴퓨터공학과
*  이름: 이준석
*/

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <strings.h>
#include <math.h>
#include "cachelab.h"


struct csimParameter {      // store all the  basic info of cache
	int s; 
	int E; 
	int b; 
	int S; 
	int B; 
	int hits;
	int misses;
	int evicts;
};

struct line{
	int LRU;
	
	int valid;
	unsigned long long tag;
	char* block;
};

struct set{
	struct line* lines;
};

struct cache{
	struct set* sets;
};

struct csimParameter paraInit()
{
	struct csimParameter _para;
	_para.s = 0;
	_para.S = 0;
	_para.E = 0;
	_para.b = 0;
	_para.B = 0;
	_para.hits = 0;
	_para.misses = 0;
	_para.evicts = 0;
	
	return _para;
}


struct cache cacheInit(int S, int E, int B)
{
	struct cache newCache;
	struct set newSets;
	struct line newLine;
	int setIndex;
	int lineIndex;
	
	
	newCache.sets = (struct set*)malloc(sizeof(struct set)*S);
	
	
	
	for(setIndex = 0; setIndex < S; setIndex++){
		newSets.lines = (struct line*)malloc(sizeof(struct line)*E);
		newCache.sets[setIndex] = newSets;
		
		for(lineIndex = 0; lineIndex < E; lineIndex++){
			newLine.LRU = 0;
			newLine.valid = 0;
			newLine.tag = 0;
			newSets.lines[lineIndex] = newLine;
		}
		
	}
	
	return newCache;
}

void free_set_line(struct cache c, int S, int E, int B)
{
	int i;
	
	for(i=0;i<S;i++){
		struct set temp = c.sets[i];
		if(temp.lines != NULL){
			free(temp.lines);
		}
	}
	if(c.sets != NULL){
		free(c.sets);
	}
}

int findEmptyLine(struct set _set, int E)
{ // 찾는데 실패하면 -1 리턴, 성공하면 해당하는 index 리턴
	int i;
	struct line _line;
	for(i=0;i<E;i++){
		_line = _set.lines[i];
		if(_line.valid == 0){ // 비어있는 line을 찾았다.
			return i;
		}
	}
	return -1; // 비어있는 line이 없다.
}

int findEvictionLine(struct set _set, struct csimParameter _para, int* LineLRU)
{
	int E = _para.E;
	int lineIndex;
	int minLRU = _set.lines[0].LRU;
	int maxLRU = _set.lines[0].LRU;
	int minIndex = 0;
		
	for(lineIndex = 0; lineIndex < E; lineIndex++){
		if(minLRU > _set.lines[lineIndex].LRU){
			minIndex = lineIndex;
			minLRU = _set.lines[lineIndex].LRU;
		}
		if(maxLRU < _set.lines[lineIndex].LRU){
			maxLRU = _set.lines[lineIndex].LRU;
		}
	}
	
	LineLRU[0] = minLRU;
	LineLRU[1] = maxLRU;
	return minIndex;	
}

struct csimParameter accessMemory(struct cache _cache // cache simulation을 할 cache
								  , struct csimParameter _para // cache simulation 결과 발생하는 hit, miss, evict의 횟수를 저장한다.
								  , unsigned long long addr // 참조할 메모리의 주소, 최대 64비트
								  )
{
		/*
	 * (1) hit여부를 판단하는 loop. hit이면 hit++하고 종료, 아니라면 2번으로
	 * (2) miss이다. miss++ 한다.
	 *  (2.1) 비어있는 곳이 있으면 그곳에 값을 채운다.
	 *  (2.2) 비어있는 곳이 없으면 evict 대상을 찾아서 갈아치운다. evict++ 한다.
	 */
	int isCacheFull = 1;
	int tagSize;
	unsigned long long tag;
	unsigned long long temp;
	unsigned long long setIndex;
	int lineIndex;
	int E;
	int preHitCount = _para.hits;
	int emptyLineIndex;
	int* lineLRU;
	int evictIndex;
	
	E = _para.E;
	tagSize = 64 - (_para.s + _para.b);
	tag = addr >> (_para.s + _para.b); // with regard to tag bit
	temp = addr << tagSize;
	setIndex = temp >> (tagSize + _para.b); // with regard to set index bit
	
	// (1)
	for(lineIndex=0; lineIndex < E; lineIndex++){
		struct line tempLine = _cache.sets[setIndex].lines[lineIndex];
		if(tempLine.valid){ // valid bit test 통과
			if(tempLine.tag == tag){ // tag bit test 통과
				// hit
				_para.hits++;
				_cache.sets[setIndex].lines[lineIndex].LRU++;
			}
		}
		else if( !(tempLine.valid)&&(isCacheFull) ){
			isCacheFull = 0;
		}
	}

	// (2)
	
	if(preHitCount == _para.hits){ // 위의 loop에서 hit이 발생하지 않았다 즉, miss이다.
		_para.misses++;
		lineLRU = (int*)malloc(sizeof(int)*2);
		evictIndex = findEvictionLine(_cache.sets[setIndex], _para, lineLRU);
		
		if(isCacheFull){ // (2.2) cache가 가득 차 있다. 
			_para.evicts++;
			_cache.sets[setIndex].lines[evictIndex].tag = tag;
			_cache.sets[setIndex].lines[evictIndex].LRU = lineLRU[1] + 1;
		}
		else{ // (2.1) cache에 비어있는 곳이 있다.
			emptyLineIndex = findEmptyLine(_cache.sets[setIndex], _para.E);
			_cache.sets[setIndex].lines[emptyLineIndex].valid = 1;
			_cache.sets[setIndex].lines[emptyLineIndex].tag = tag;
			_cache.sets[setIndex].lines[emptyLineIndex].LRU = lineLRU[1] + 1;
		}
		free(lineLRU);
		return _para;
	}
	else{
		return _para;
	}	
}




void printUsage(char* argv[])
{
    printf("Usage: %s [-hv] -s <num> -E <num> -b <num> -t <file>\n", argv[0]);
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    printf("\nExamples:\n");
    printf("  %s -s 4 -E 1 -b 4 -t traces/yi.trace\n", argv[0]);
    printf("  %s -v -s 8 -E 2 -b 4 -t traces/yi.trace\n", argv[0]);
    exit(0);
}



int main(int argc, char** argv)
{
	
	int c;
	struct csimParameter _para;
	struct cache cache_test;
	char* traceFileName;
	FILE* traceFile;
	int setNum; // set의 개수
	int blockNum; // block의 칸 수(바이트 수)
	
	//variables for reading a trace file
	char instruction;
	unsigned long long int memory;
	int type;
	
	
	_para = paraInit();
	
	while((c = getopt(argc,argv,"s:E:b:t:vh")) != -1){
		switch(c)
		{
			case 's':
				_para.s = atoi(optarg);
				break;
			case 'E':
				_para.E = atoi(optarg);
				break;
			case 'b':
				_para.b = atoi(optarg);
				break;
			case 't':
				traceFileName = optarg;
				break;
			case 'v':
				break;
			case 'h':
				break;
			default:
				break;
		}
	}
	
	setNum = pow(2.0, _para.s);
	blockNum = pow(2.0, _para.b);
	_para.S = setNum;
	_para.B = blockNum;
	cache_test = cacheInit(_para.S, _para.E, _para.B);
	
	traceFile = fopen(traceFileName, "r");
	if(traceFile != NULL){
		while(fscanf(traceFile, " %c %llx,%d", &instruction, &memory, &type) == 3){
			switch(instruction){
				case 'I':
					break;
				case 'S':
					_para = accessMemory(cache_test, _para, memory);
					break;
				case 'L':
					_para = accessMemory(cache_test, _para, memory);
					break;
				case 'M':
					_para = accessMemory(cache_test, _para, memory);
					_para = accessMemory(cache_test, _para, memory);
					break;
				default:
					break;
			}
		}
	}

    printSummary(_para.hits, _para.misses, _para.evicts);
	free_set_line(cache_test, _para.S, _para.E, _para.B);
	fclose(traceFile);
    return 0;
}