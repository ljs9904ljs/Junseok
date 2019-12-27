/*
*  학번: 20180551
*  학과: 컴퓨터공학과
*  이름: 이준석
*/

/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"


int is_transpose(int M, int N, int A[N][M], int B[M][N]);
void trans_64_64(int M, int N, int A[N][M], int B[M][N]);
void trans_32_32(int M, int N, int A[N][M], int B[M][N]);
void trans_61_67(int M, int N, int A[N][M], int B[M][N]);
/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. The REQUIRES and ENSURES from 15-122 are included
 *     for your convenience. They can be removed if you like.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    if(M==32)
    {
        trans_32_32(M,N,A,B);
    }
    if(M==64)
    {
        trans_64_64(M,N,A,B);
    }
    if(M==61)
    {
        trans_61_67(M,N,A,B);
    }
}

void trans_32_32(int M, int N, int A[M][N], int B[N][M])
{
    int bSize;
	int i, j, i1, j1;
	int temp = 0;
	int d = 0;
	bSize = 8;
		for (j = 0; j < N; j += bSize) {
			
			for (i = 0; i < N; i += bSize) {
				
				for(i1 = i; i1 < i + bSize; i1++) {
					
					for(j1 = j; j1 < j + bSize; j1++) {
					
						if(j1 != i1){
							B[j1][i1] = A[i1][j1];
						}
						
						else{
							temp = A[j1][i1];
							d = j1;
						}
						
					}
					if(j == i){
						B[d][d] = temp;
					}

				}
			}
		}
}

void trans_64_64(int M, int N, int A[N][M], int B[N][M])
{
    int dy, dx, k, t0, t1, t2, t3, t4, t5, t6, t7; 

    for(dy=0; dy<64; dy+=8 ){
       	for(dx=0; dx<64; dx+=8 ){

        
        	for(k=0; k<4; k++){ 
        		t0 = A[dy+k][dx+0];
        		t1 = A[dy+k][dx+1];
        		t2 = A[dy+k][dx+2];
        		t3 = A[dy+k][dx+3];
        		t4 = A[dy+k][dx+4];
        		t5 = A[dy+k][dx+5];
        		t6 = A[dy+k][dx+6];
        		t7 = A[dy+k][dx+7];

        	
        		B[dx+0][dy+k+0] = t0; 
        		B[dx+0][dy+k+4] = t5;
        		B[dx+1][dy+k+0] = t1;	
        		B[dx+1][dy+k+4] = t6;	
        		B[dx+2][dy+k+0] = t2;	
        		B[dx+2][dy+k+4] = t7;	
        		B[dx+3][dy+k+0] = t3;	
        		B[dx+3][dy+k+4] = t4;	
        	}

        	t0 = A[dy+4][dx+4];
        	t1 = A[dy+5][dx+4];
        	t2 = A[dy+6][dx+4];
        	t3 = A[dy+7][dx+4];
        	t4 = A[dy+4][dx+3];
        	t5 = A[dy+5][dx+3];
        	t6 = A[dy+6][dx+3];
        	t7 = A[dy+7][dx+3];

        	B[dx+4][dy+0] = B[dx+3][dy+4];  
        	B[dx+4][dy+4] = t0;  
        	B[dx+3][dy+4] = t4;
        	B[dx+4][dy+1] = B[dx+3][dy+5];
        	B[dx+4][dy+5] = t1;
        	B[dx+3][dy+5] = t5;
        	B[dx+4][dy+2] = B[dx+3][dy+6];
        	B[dx+4][dy+6] = t2;
        	B[dx+3][dy+6] = t6;
        	B[dx+4][dy+3] = B[dx+3][dy+7];
        	B[dx+4][dy+7] = t3;
        	B[dx+3][dy+7] = t7;

        	for(k=0;k<3;k++){

        		t0 = A[dy+4][dx+5+k];
        		t1 = A[dy+5][dx+5+k];
        		t2 = A[dy+6][dx+5+k];
        		t3 = A[dy+7][dx+5+k];
        		t4 = A[dy+4][dx+k];
        		t5 = A[dy+5][dx+k];
        		t6 = A[dy+6][dx+k];
        		t7 = A[dy+7][dx+k];

        		B[dx+5+k][dy+0] = B[dx+k][dy+4];
        		B[dx+5+k][dy+4] = t0;
        		B[dx+k][dy+4] = t4;
        		B[dx+5+k][dy+1] = B[dx+k][dy+5];
        		B[dx+5+k][dy+5] = t1;
        		B[dx+k][dy+5] = t5;
        		B[dx+5+k][dy+2] = B[dx+k][dy+6];
        		B[dx+5+k][dy+6] = t2;
        		B[dx+k][dy+6] = t6;
        		B[dx+5+k][dy+3] = B[dx+k][dy+7];
        		B[dx+5+k][dy+7] = t3;
        		B[dx+k][dy+7] = t7;
        	}
        }
	}	

}

void trans_61_67(int M, int N, int A[N][M], int B[M][N])
{
    int i,j,i1,j1;
    int temp;

    for(i=0; i<M; i+=18)
    {
        for(j=0; j<N; j+=18)
        {
            for(i1=i; (i1<(i+18)) && (i1<M); i1++)
            {
                for(j1=j; (j1<(j+18)) && j1<N; j1++)
                {
                    if((i1)==(j1))
                    {
                        temp=A[i1][i1];
                    }
                    else
                    {
                        B[i1][j1]=A[j1][i1];
                    }
                }
                if(i==j)
                {
                    B[i1][i1]=temp;
                }

            }

        }
    }

}


/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    } 
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);

}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; ++j)
        {
            if (A[i][j] != B[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}