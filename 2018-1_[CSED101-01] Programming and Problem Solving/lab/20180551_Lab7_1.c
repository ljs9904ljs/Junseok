#include<stdio.h>

int sigma(int a, int b);
int sigma_rec(int a, int b);


int main()
{
	int a, b;

	printf("2���� �����Է�: ");
	scanf("%d %d", &a, &b);

	printf("%d\n", sigma(a, b)); // �ݺ���
	printf("%d\n", sigma_rec(a, b)); // ����Լ�

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

