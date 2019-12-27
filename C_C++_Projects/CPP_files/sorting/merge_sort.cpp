#include<iostream>

using namespace std;


int arr[9] = {9, 7, 5, 2, 4, 2, 2, 4, 6};
int* arr_t;

void merge(int left, int right) {
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j])
            arr_t[k++] = arr[i++];
        else
            arr_t[k++] = arr[j++];
    }

    int r = ((i > mid) ? j : i);

    while(k<=right)
        arr_t[k++] = arr[r++];

    for(int idx=left;idx<=right;idx++) 
        arr[idx] = arr_t[idx];
    
}

void merge_sort(int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid+1, right);
        merge(left, right);
    }
    return;
}

int main() {

    int i, n;
    n = 9;
    arr_t = new int[n];

    printf(" { ");
    for(i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("}");


    merge_sort(0, 8);

    printf(" -> { ");
    for(i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("}");

    delete arr_t;

    return 0;
}