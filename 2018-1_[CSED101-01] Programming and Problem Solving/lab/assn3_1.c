#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_PLAYER 10


void GenerateLadder(int num_player, int num_hline, int ladder[][2]);
int SaveLadder(int num_player, int num_hline, int ladder[][2]);

int main()
{
	int people; //참여 인원 수
	int garo;   //가로줄의 개수
	int ladder[(MAX_PLAYER - 1) * 5][2]; //사다리를 저장할 2차원 배열, 가로줄 있으면 1 없으면 0 저장

	srand(time(NULL));
	
		printf("참여인원수: "); 
		scanf("%d", &people); //참여인원수를 입력받는다.
		printf("가로줄 개수: ");
		scanf("%d", &garo);// 가로줄의 개수를 입력받는다.

		if (people < 2 || people >10) //여기서부터 조건문을 돌려서 참여인원수와 가로줄의 개수의 범위에 맞는 입력만을 허락토록한다. 조건에 맞지 않으면 프로그램을 종료한다.
		{
			printf("입력이 잘못됐습니다.\n");
			return 0;
		}
		else if (2 <= people && people <= 4)
		{
			if (garo < 0 || garo >10)
			{
				printf("입력이 잘못됐습니다.\n");
				return 0;
			}
		}
		else if (5 <= people && people <= 7)
		{
			if (garo < 0 || garo > 20)
			{
				printf("입력이 잘못됐습니다.\n");
				return 0;
			}
		}
		else if (8 <= people && people <= 10)
		{
			if (garo < 0 || garo > 30)
			{
				printf("입력이 잘못됐습니다.\n");
				return 0;
			}
		}
		
			ladder[0][0] = people; //배열의 1행 1열에 참가자 수를 저장한다
			ladder[0][1] = garo;   //배열의 1행 2열에 가로줄의 개수를 저장한다
			GenerateLadder(people, garo, ladder); // 사다리를 생성한다.
			SaveLadder(people, garo, ladder); // 사다리를 텍스트 파일에 저장한다.
		

	return 0;
}

void GenerateLadder(int num_player, int num_hline, int ladder[][2]) // 사다리를 생성하는 함수
{

	while (1) //가로줄을 어디에 그을지 (2차원 배열에 입력)
	{
		int i, check = 1;
		for (i = 1;i <= num_hline;i++) // 배열의 1열에 1~10 사이의, 사다리의 세로 번호 랜덤하게 저장 ( 얘는 조건이 없다.)
		{
			ladder[i][0] = rand() % 10 + 1;
		}

		for (i = 1;i <= num_hline;i++) // 배열의 2열에 가로줄의 가로 위치를 랜덤하게 저장 ( 얘는 조건이 있다.)
		{
			ladder[i][1] = rand() % (num_player - 1) + 1;
		}
		//배열의 2열에 대한 조건을 충족시키기 위해서 while(1)을 쓰고, 조건 충족 시 while문을 break하기 위해 아래 문장 사용
		int j;
		int k;
		for (j = 1;j <= num_hline;j++)
		{
			for (k = 1;k <= num_hline;k++)
			{
				if (ladder[j][0] == ladder[k][0])  //사다리의 세로 번호가 같다면
				{
					if (ladder[j][1] + 1 == ladder[k][1]) 
					{
						check = 0;
						break; // if 조건을 충족하면 break한다.
					}
				}//세로줄이 같다면
			}//k의 for문
			if (check == 0)
				break;
		}//j의 for문
		if (check == 1)
			break;
	}//while문
}

int SaveLadder(int num_player, int num_hline, int ladder[][2]) // 만들어진 사다리에 대한 데이터를 텍스트 파일로 저장해낸다.
{
	FILE* output;
	int i,j;
	output = fopen("map.txt", "w");
	if (output == NULL)
		printf("cannot open file\n");
	else
	{
			for (i = 0;i <= num_hline;i++)
			{
				for (j = 0;j <= 1;j++)
				{
					fprintf(output, "%d ", ladder[i][j]);
				}
				fprintf(output, "\n");
			}

	}
	fclose(output);

	return 0;
}

