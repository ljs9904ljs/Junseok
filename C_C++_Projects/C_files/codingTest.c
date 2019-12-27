#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node {
    int start;
    int end;
} node;

void printList(node* list, int n) {
    for(int i=0;i<n;i++) {
        if(list[i].start == -1 && list[i].end == -1) continue;
        printf("(%d, %d), ", list[i].start, list[i].end);
    }
    printf("\n");
}


int main() {
    int n;
    scanf("%d", &n);

    node* list = (node*)malloc(sizeof(node)*n);

    for(int i=0;i<n;i++) {
        scanf("%d %d", &list[i].start, &list[i].end);
    }

    printList(list, n);

    for(int i=0;i<n;i++) {
        if(list[i].start == -1 && list[i].end == -1) continue;
        for(int j=i+1;j<n;j++) {
            if(list[i].end >= list[j].start) {
                list[i].end = list[j].end;
                list[j].start = -1;
                list[j].end = -1;
                
            }
        }
    }

    printList(list, n);

    free(list);

    return 0;
}