#include<stdio.h>

int seqSearch(int a[], int n, int target);

int main()
{
	int a[10] = { 0 };
	int target;
	int i;

	printf("Input 10 integer values: ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("Entered number is	 ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("Input an integer that you want to find: ");
	scanf("%d", &target);
	int where = seqSearch(a, 10, target);
	if (where == -1)
		printf("Not Found\n");
	else
		printf("The index of %d is %d\n", target, where);

	return 0;
}

int seqSearch(int a[], int n, int target)
{
	int i;
	for (i = 0; i <n; i++)
	{
		if (a[i] == target)
			return i;
	}
	return -1;
}