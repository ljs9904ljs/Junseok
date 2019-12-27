#include<stdio.h>


#define MAX 6



void bubble_sort(int a[], int size);
void swap(int *x, int *y);
void print_array(int a[], int size);
void input_array(int a[], int size);



int main()
{
	int arr[MAX];


	printf("Input integer numbers to be sorted: ");
	input_array(arr, MAX);

	printf(" Unsorted: ");
	print_array(arr, MAX);

	printf("\n----------------------------------");
	bubble_sort(arr, MAX);
	printf("\n----------------------------------\n");

	printf("   Sorted: ");
	print_array(arr, MAX);

	return 0;
}
void input_array(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &a[i]);
	}
}

void print_array(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%2d ", a[i]);
	}
}

void swap(int*x, int*y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void bubble_sort(int a[], int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = size - 1; i > 0; i--)
		{
			if (a[i] < a[i - 1])
				swap(&a[i], &a[i - 1]);
		}
		printf("\n[step %d]  ", j + 1);
		print_array(a, MAX);
	}
}