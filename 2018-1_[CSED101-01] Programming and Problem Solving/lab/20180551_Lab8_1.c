#include<stdio.h>

#define MAX_SIZE 20

void print_matrix(int arr[MAX_SIZE][MAX_SIZE], int size);


int main()
{
	int size;
	size = 0;
	printf("Enter the size of square:  ");
		scanf(" %d", &size);
	
		int arr[MAX_SIZE][MAX_SIZE] = { 0 };
	


	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == size-j-1)
			{
				arr[i][j] = 0;
			}
			else if (i < size - j)
			{
				arr[i][j] = 1;
			}
			else
				arr[i][j] = -1;
		}
	}

	print_matrix(arr, size);




	return 0;
}




void print_matrix(int arr[MAX_SIZE][MAX_SIZE], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

}