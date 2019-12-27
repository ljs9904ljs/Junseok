#include<stdio.h>


int main()
{

	printf("게임을 위한 계단의 개수를 입력(10~30) >> ");

	int stair;
	scanf(" %d", &stair);





	if (stair >= 10 && stair <= 30 && stair % 2 == 1)   // 계단 개수가 10~30이라면 실행한다 그리고 홀수일 때
	{
		int a, b, c;


		for (a = 0; a < (stair / 2 + 1); a++)  // 계단 개수가 홀수 일 때
		{
			for (b = 0; b <= a; b++)
			{
				printf("▩");
			}
			for (b = 0; b <= -3 + (stair - 1 - 2 * (a - 1)); b++)
			{
				printf("  ");
			}
			for (c = 0; c <= a; c++)
			{
				printf("▩");
			}
			printf("\n");
		}

	}
	
	if (stair >= 10 && stair <= 30 && stair % 2 == 0) // 계단 개수가 10~30이라면 실행한다 그리고 짝수일 때
	{
		int i, j, k;

		for (i = 0; i < (stair / 2); i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf("▩");
			}
			for (j = 0; j <= (stair - 1 - 2 * (i - 1)); j++)
			{
				printf("  ");
			}
			for (k = 0; k <= i, k++)
			{
				printf("▩");
			}
			printf("\n");
		}


	}

	return 0;
}

//공을 움직이는 함수를 만들자. 첫 칸은 그냥 하고 둘 째 칸은 \n하고 스페이스바 두 번 누르는 식으로 하자.
