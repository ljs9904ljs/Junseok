#include <stdio.h>
#include <math.h>

int main(){
    int a = (int)(sqrt(20180551)*100000);
    a= a % 10000;
    printf("%d", a);
// Code=MOD(INT(SQRT(학번) *
// 100000),10000)

    return 0;
}