#include<stdio.h>
#include<stdlib.h>
void find_minmax(const int *arr, int size, int *max, int *min);
int main()
{
	int size,max,min;
	int*arr;
	int i;
	printf("Enter array size :");
	scanf("%d", &size);
	arr = (int*)malloc(sizeof(int)*size);
	for (i = 0; i < size; i++)
		scanf("%d", arr + i);
	printf("\nEntered numbers are\n");
	for (i = 0; i < size; i++)
		printf("%d ", *(arr + i));
	find_minmax(arr, size, &max, &min);
	printf("\nMaximum is %d", max);
	printf("\nMinimum is %d", min);
	printf("\nEnter changed array size :");
	scanf("%d", &size);
	(int*)realloc((int*)arr, sizeof(int)*size);
	for (i = 0; i < size; i++)
		scanf("%d", arr + i);
	printf("\nEntered numbers are\n");
	for (i = 0; i < size; i++)
		printf("%d ", *(arr + i));
	find_minmax(arr, size, &max, &min);
	printf("\nMaximum is %d", max);
	printf("\nMinimum is %d", min);
	free((int*)arr);
	return 0;
}

void find_minmax(const int *arr, int size, int *max, int *min)
{
	*max = *arr;
	*min = *arr;
	int i;
	for (i=1; i < size ; i++)
	{
		if (*min > *(arr+i))
			*min = *(arr + i);
		if (*max <  *(arr + i))
			*max = *(arr + i);
	}
}
