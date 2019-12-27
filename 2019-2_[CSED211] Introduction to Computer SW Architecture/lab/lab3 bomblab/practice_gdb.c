#include <stdio.h>

void foo(int);
void wrong_input();

int main()
{
	int a;
	printf("What is the solution?\n");
	printf("Answer: ");
	scanf("%d", &a);
	foo(a);	


}

void foo(int x)
{
	if(x == 2695)
	{
		printf("Funny MicroProcessor\n");
	}
	else
	{
		wrong_input();
	}
}

void wrong_input()
{
	printf("Your input is wrong!\n");
}



