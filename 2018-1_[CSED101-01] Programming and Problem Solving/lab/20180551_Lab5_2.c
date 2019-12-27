#include<stdio.h>

int main()
{
	int a;
	int b;
	int result;


	for (b = 1; b <= 9; b++)
	{
		for (a = 2; a <= 9; a++)
		{
		result = a * b;
		printf("%d * %d = %2d  ", a, b, result);
	    }
		printf("\n");
	}




	return 0;
}
