#include<stdio.h>

int sigma(int a, int b);
int sigma_rec(int a, int b);


int main()
{
	int a, b;

	printf("2개의 정수입력: ");
	scanf("%d %d", &a, &b);

	printf("%d\n", sigma(a, b)); // 반복문
	printf("%d\n", sigma_rec(a, b)); // 재귀함수

	return 0;
}

int sigma(int a, int b)
{
	int i;
	int sum=0;
	for (i = a; i <= b; i++)
	{
		sum = sum + i;
	}
	return sum;
}

int sigma_rec(int a, int b)
{
	if (a == b)
		return a;
	else
	{
		return a + sigma_rec(a+1,b);
	}
}

