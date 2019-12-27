#include<stdio.h>

int main()
{
	int a;
	int b;
	int result;
	printf("출력하고 싶은 단을 입력하시오: ");
	scanf_s("%d", &a);

	for (b=1 ; b<=9 ; b++ )
	{
		result = a * b;
		printf("%d * %d = %d\n", a, b, result);
	}




	return 0;
}