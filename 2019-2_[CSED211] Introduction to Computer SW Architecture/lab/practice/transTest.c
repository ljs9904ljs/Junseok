#include <stdio.h>

void printMatrix(int M, int N, int arr[3][3])
{
    int i,j;
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void trans(int M, int N, int src[3][3], int dest[3][3])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = src[i][j];
            dest[j][i] = tmp;
        }
    }   
}

int main(){
    int destArr[3][3] = {0};
    int myArr[3][3] = {1,2,3,
                       4,5,6,
                       7,8,9};
    printMatrix(3,3,myArr);
    trans(3,3,myArr,destArr);


    return 0;
}