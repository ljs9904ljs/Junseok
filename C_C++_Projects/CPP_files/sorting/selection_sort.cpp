#include<iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void selection_sort(int list[], int n) {
    // n은 list의 원소 개수

    int i, j, least;

    for(i=0;i<n-1;i++) {
        least = i;

        for(j=i+1;j<n;j++) {
            if(list[j] < list[least])
                least = j;
        }

        if(i != least)
            swap(list[i], list[least]);
    }
}


int main() {

    int i, n;
    n = 9;
    int list[] = {9, 7, 5, 2, 4, 2, 2, 4, 6};

    printf(" { ");
    for(i=0;i<n;i++) {
        printf("%d ", list[i]);
    }
    printf("}");


    selection_sort(list, n);

    printf(" -> { ");
    for(i=0;i<n;i++) {
        printf("%d ", list[i]);
    }
    printf("}");
    return 0;
}