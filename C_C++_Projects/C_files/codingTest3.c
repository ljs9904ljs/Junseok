#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct count {
    char c;
    int count;
} count;



int main() {
    char roomNumber[100];
    int length, i, j;
    count cnt[100];

    scanf("%s", roomNumber);

    length = strlen(roomNumber);

    for(i=0;i<length;i++) {
        cnt[i].c = 'a';
        cnt[i].count = 0;
    }
    printf("\n%s\n\n", roomNumber);
    for(i=0;i<length;i++) {
        for(j=i;j<length;j++) {
            if(cnt[i].c != roomNumber[j]) {
                cnt[i].c = roomNumber[j];
                cnt[i].count = 1;
            }
            else if(cnt[i].c == roomNumber[j]) {
                cnt[i].count += 1;
            }
        }
    }

    for(i=0;i<length;i++) 
        printf("'%c' : %d\n", cnt[i].c, cnt[i].count); 


    return 0;
}