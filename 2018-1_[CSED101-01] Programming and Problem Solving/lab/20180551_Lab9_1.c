#include <stdio.h>

void partial_print(int *arr_start, int size);
int partial_sum(int *arr_start, int *arr_end);

int main()
{
	int arr[10];

	printf("Enter 10 elements of array: ");
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	int j;
	printf("Numbers that you enter are: ");
	for (j = 0; j < 10; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");

	printf("Enter the starting and ending index: ");
	int starting, ending;

	scanf("%d %d", &starting, &ending);
	printf("\n");
	

	int p_sum;
	p_sum = partial_sum(arr + starting, arr + ending);

	printf("sum from array[%d] to array[%d] is %d\n", starting, ending, p_sum);
	printf("partial array output: ");
	partial_print(arr + starting, ending - starting);

	return 0;
}


void partial_print(int *arr_start, int size)
{
	int i;
	for (i = 0; i <= size; i++)
		printf("%d ", *(arr_start + i));
}

int partial_sum(int *arr_start, int *arr_end)
{
	int i;
	int total = 0;
	for (i = 0; i <= (arr_end - arr_start); i++)
	{
		total = total + *(arr_start + i);
	}
	return total;
}
