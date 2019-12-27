#include <iostream>

using namespace std;

int N,arr[1000001];
int *arr2;

void merge_sort(int left, int right)
{
    int mid = (left + right) / 2;
    int i = left;
    int j = mid+1;
    int k = left;

    while(i<=mid && j<=right){
        if(arr[i] <= arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }

    int remainder = i>mid ? j : i;
    while(k<=right){
        arr2[k++] = arr[remainder++];
    }
    for(int i=left;i<=right;i++){
        arr[i] = arr2[i];
    }
}

void part(int left, int right)
{
    int mid = (left + right) / 2;
    if(left < right){
        part(left, mid);
        part(mid+1, right);
        merge_sort(left, right);
    }
}



int main(){
    scanf("%d",&N);
    arr2 = new int[N];

    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);

    part(0, N-1);

    printf("\n\n\n");
    for(int i=0;i<N;i++)
        printf("%d\n", arr[i]);

    return 0;
}