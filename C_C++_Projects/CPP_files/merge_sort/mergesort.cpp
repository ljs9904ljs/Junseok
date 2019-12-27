/*
void merge(int left, int right)
{
    //사용할 변수 선언
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int k = left;

    //왼쪽과 오른쪽에 대해 이동하면서 정렬하면서 저장
    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }
    //왼쪽을 다 써버렸는지 오른쪽을 다 써버렸는지에 따라 남은 걸 채울 때 인덱스가 결정된다.
    int temp = i>mid ? j : i;

    //남은 칸을 채운다.
    while(k<=right) arr2[k++] = arr[temp++];

    //임시 배열에 정렬된 값이 저장되어 있다. 그것을 다시 원래 배열로 옮긴다.
    for(int i=left;i<=right;i++) arr[i] = arr2[i];
}

void partition(int left, int right)
{
    int mid;
    if(left<right) // 에러 체크, 왼쪽 인덱스가 오른쪽 인덱스보다 작아야 됨.
    {
        mid = (left+right)/2;
        partition(left,mid);
        partition(mid+1,right);
        merge(left,right);
    }
}
*/

#include <iostream>

using namespace std;

int N,arr[1000001];
int *arr2;

void part(int left, int right)
{
    int mid = (left + right) / 2;
    if(left < right){
        part(left, mid);
        part(mid+1, right);
        merge_sort(left, right);
    }
}

void merge_sort(int left, int right)
{
    int mid = (left + right) / 2;
    int i = left;
    int j = mid+1;
    int k = left;

    while(i<=mid && j<=right){
        if(arr[i] < arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }

    int remainder = i>mid ? j : i;
    while(k<=right){
        arr2[k++] = arr[remainder++];
    }
    for(int i=left;i<right;i++){
        arr[i] = arr2[i];
    }

}

int main(){
    scanf("%d",&N);
    arr2 = new int[N];

    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);

    part(0, N-1);

    for(int i=0;i<N;i++)
        printf("%d\n", arr[i]);

    return 0;
}