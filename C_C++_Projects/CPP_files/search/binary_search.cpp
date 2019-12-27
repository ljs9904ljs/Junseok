#include<iostream>
#include<cstdlib>
#include<ctime>

int arr2[10000];


int binarySearch(int arr[], int left, int right, int x) {
    if (right >= 1) {
        int mid = (left + right - 1) / 2;

        if(arr[mid] == x)
            return mid;
        
        if(arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        
        if(arr[mid] < x)
            return binarySearch(arr, mid + 1, right, x);
    }

    return -1; // we can't find the value 'x'.
}

void merge(int arr[], int left, int right) {
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }

    int tmp = i > mid ? j : i;

    while(k<=right)
        arr2[k++] = arr[tmp++];

    for(int p=left;p<=right;p++)
        arr[p] = arr2[p];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}

int main() {
    srand(unsigned(time(NULL)));

    int a[10];
    for(int i=0;i<10;i++) {
        a[i] = rand() % 90 + 11;
    }

    for(int i=0;i<10;i++) {
        printf("%d, ",a[i]);
    }
    std::cout << std::endl;

    mergeSort(a, 0, 9);

    for(int i=0;i<10;i++) {
        printf("%d, ",a[i]);
    }
    std::cout << std::endl;

    printf("=================\n\n");

    int n;
    std::cin >> n;

    int v = binarySearch(a, 0, 9, n);
    if(v == -1) {
        std::cout << "Error: can't find" << std::endl;
        return 0;
    }
    printf("I find the value %d in the index %d :: %d \n", n, v, a[v]);

    return 0;
}