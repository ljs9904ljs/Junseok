#include<stdio.h>
#include "calc.h"

int main()
{
	printf("Enter two intergers: ");
	int a, b;
	scanf("%d %d", &a, &b);
	printf("Results: \n");
	printf("%d + %d = %d\n", a, b, add(a, b));
	printf("%d - %d = %d\n", a, b, sub(a, b));
	printf("%d * %d = %d\n", a, b, mul(a, b));
	printf("%d / %d = %.2f\n", a, b, div(a, b));



	return 0;
}