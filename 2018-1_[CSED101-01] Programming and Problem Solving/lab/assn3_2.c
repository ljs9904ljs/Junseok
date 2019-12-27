#include<stdio.h>

#define MAX_ROW 100
#define MAX_COL 100
#define ORANGE "\x1b[91m"
#define GREEN "\x1b[92m"
#define YELLOW "\x1b[93m"
#define BLUE "\x1b[94m"
#define PURPLE "\x1b[95m"
#define RESET "\x1b[0m"
#define FLUSH while(getchar()!='\n')


int LoadLadder(int ladder_board[][MAX_COL], int people, FILE* infile);
void ladder_game(int ladder_board[][MAX_COL], int path, int starting_point, int people, int count);
void print_ladder_game(int ladder_board[][MAX_COL], int people);
void result_save(FILE* outfile, int ladder_board[][MAX_COL], int path, int starting_point, int people, int count);

int main()
{
	int ladder_board[MAX_ROW][MAX_COL];
	int people, garo, i, j, count = 0;
	FILE* infile;
	FILE* outfile;

	infile = fopen("map.txt", "r"); //기존에 존재하던 map.txt 파일을 연다.
	if (infile == NULL)
		printf("cannot open file.\n");

	fscanf(infile, "%d %d", &people, &garo); // txt파일의 맨 위에 저장되어있는 (참가자 수, 가로줄의 개수)를 읽어온다. 
										

	outfile = fopen("result.txt", "w"); // 사다리 게임의 결과를 저장할 result.txt 파일을 쓰기 모드로 열어둔다.
	if (outfile == NULL)
		printf("cannot open file");



	LoadLadder(ladder_board, people, infile); // 정확한 좌표에 입각한 사다리를 만든다.

	for (i = 0; i < people; i++)
		printf("%c  ", 'A' + i); // 목적지 출력
	printf("\n");

	print_ladder_game(ladder_board, people); // 사다리 출력

	for (i = 1; i <= people; i++) // 출발지 출력
		printf("%d  ", i);
	printf("\n");

         // 아래는 출발 지점을 입력받아 그에 따른 사다리 게임을 진행하도록 하는 것이다.
	while (1) {                   
		int starting_point;
		printf(">> ");
		scanf("%d", &starting_point);
		FLUSH;


		int path;
		path = 2 * (starting_point - 1); // 출발지점을 사다리 판의 정확한 좌표로 치환하는 과정

		                               // 아래는 입력받은 값이 0이 아니고 -1이 아닐 때, 게임을 진행한다는 내용
		if (starting_point != 0 && starting_point != -1) { 
			ladder_game(ladder_board, path, starting_point, people, count);
			count += 1;
		}
		else
		{
			if (starting_point == 0)  // 0을 입력받으면 반복문을 탈출하여 프로그램을 종료한다.
				break;
			else if (starting_point == -1) // -1을 입력받으면 사다리 게임의 모든 경우의 수에 따른 게임 결과들을 출력한다.
			{
				int c;

					  for (c = 1; c <= people; c++)
				{
					ladder_game(ladder_board, (2 * c - 2), c, people, -1);
					fprintf(outfile, "%d\n", c);
					result_save(outfile, ladder_board, (2 * c - 2), c, people, count);
					fprintf(outfile, "\n\n");
				}
			}
		}
	}



	return 0;
}

int LoadLadder(int ladder_board[][MAX_COL], int people, FILE* infile) //map.txt로부터 입력받은 값을 통해 정확한 사다리 판을 만드는 과정이다. 사다리가 없는 부분에 0을 저장한다.
{
	FILE* input;
	int i, j;
	int temp1, temp2;

	input = infile;
	if (input == NULL)
	{
		printf("cannot open file.\n");
		return 0; 
	}

	else
	{
		for (i = 0;i < 12;i++) // 무조건 그려지는 세로줄 부분 그리기
		{
			for (j = 1;j <= people;j++)
				ladder_board[i][2 * j - 2] = 1;
		}

		while (fscanf(input, "%d %d", &temp1, &temp2) != EOF) //가로줄 그리기
		{
			ladder_board[temp1][2 * (temp2)-1] = 1;
		}

		for (i = 0;i < 12;i++) //사다리가 안 그려지는 곳에는 2중 for문으로 0을 저장한다.
		{
			for (j = 0;j <= people;j++)
			{
				if (ladder_board[i][2 * j + 1] == 1)
				{
					continue; // 1이 저장되어 있으면 아래의 0을 저장하는 단계를 건너뛰고 1이 저장된 채로 내비둔다.
				}
				ladder_board[i][2 * j + 1] = 0;
			}
		}

		fclose(input);

		return 1;  
	}

}

void ladder_game(int ladder_board[][MAX_COL], int path, int starting_point, int people, int count) // 사다리 게임을 진행하는 함수이다. 게임을 진행하며 사다리도 함께 출력한다.
{
	int i,a = 11;
	int p;

	while (count != -1 && a > -1) //사다리 게임을 하고 출력도 한다. count가 -1이 아닐 때는 게임을 진행하고 출력도 한다.
	{
		if (path > 0 && ladder_board[a][path - 1] != 0)  // path왼쪽에 사다리가 있나 확인하는 작업.
		{
			ladder_board[a][path] = starting_point + 1;
			
			system("clear");
			printf("%d %d \n",a, path);
			for (i = 0; i < people; i++)
				printf("%c  ", 'A' + i);
			printf("\n");
			print_ladder_game(ladder_board, people);
			for (i = 1; i <= people; i++)
				printf("%d  ", i);
			printf("\n");
			p = getchar();

			ladder_board[a][--path] = starting_point + 1; // --(가로줄)에 대한 이동

			system("clear");
			printf("%d %d \n", a, path);
			for (i = 0; i < people; i++)
				printf("%c  ", 'A' + i);
			printf("\n");
			print_ladder_game(ladder_board, people);
			for (i = 1; i <= people; i++)
				printf("%d  ", i);
			printf("\n");
			p = getchar();

			ladder_board[a][--path] = starting_point + 1; // --에 대한 이동 이후에 +(세로줄)로 도착
			--a;
		}
		else if (path < 2 * (people - 1) && ladder_board[a][path + 1] != 0) // path가 오른쪽 끝줄이었어도 잘 되겠지?, path오른쪽에 사다리가 있나 확인한다
		{
			ladder_board[a][path] = starting_point + 1;

			system("clear");
			printf("%d %d \n", a, path);
			for (i = 0; i < people; i++)
				printf("%c  ", 'A' + i);
			printf("\n");
			print_ladder_game(ladder_board, people);
			for (i = 1; i <= people; i++)
				printf("%d  ", i);
			printf("\n");
			p = getchar();

			ladder_board[a][++path] = starting_point + 1; // 바로 위의 if문에 대한 내용과 같다고 보면 된다.

			system("clear");
			printf("%d %d \n", a, path);
			for (i = 0; i < people; i++)
				printf("%c  ", 'A' + i);
			printf("\n");
			print_ladder_game(ladder_board, people);
			for (i = 1; i <= people; i++)
				printf("%d  ", i);
			printf("\n");
			p = getchar();

			ladder_board[a][++path] = starting_point + 1;
			--a;
		}
		else
		{
			ladder_board[a--][path] = starting_point + 1;
		}
		printf("%d %d\n",a,path);

		system("clear");
		printf("%d %d \n", a+1, path);
		for (i = 0; i < people; i++)
			printf("%c  ", 'A' + i);
		printf("\n");
		print_ladder_game(ladder_board, people);
		for (i = 1; i <= people; i++)
			printf("%d  ", i);
		printf("\n");
		p = getchar();
	}
    

	while (count == -1 && a > -1) //count가 -1일 때에는 사다리 게임을 하는데 사다리를 출력을 하지는 않고 게임의 결과만을 도출해낸다.
	{
		if (path > 0 && ladder_board[a][path - 1] != 0)  // path왼쪽에 사다리가 있나 확인하는 작업.
		{
			ladder_board[a][path] = starting_point + 1;
			ladder_board[a][--path] = starting_point + 1; // --(가로줄)에 대한 이동
			ladder_board[a][--path] = starting_point + 1; // --에 대한 이동 이후에 +(세로줄)로 도착
			--a;
		}
		else if (path < 2 * (people - 1) && ladder_board[a][path + 1] != 0) // path오른쪽에 사다리가 있나 확인한다
		{
			ladder_board[a][path] = starting_point + 1;
			ladder_board[a][++path] = starting_point + 1; // 바로 위의 if문에 대한 내용과 같다고 보면 된다.
			ladder_board[a][++path] = starting_point + 1;
			--a;
		}
		else
		{
			ladder_board[a--][path] = starting_point + 1;
		}
	}

	if (count != -1) // 하나씩 게임을 진행할 때 결과 출력
	{
	printf("result: %d -> ", starting_point); 
	printf("%c", 'A' + path / 2);
	printf("\n");
	}
	else // 모든 경우의 수에 대한 게임의  결과를 출력해야하는 경우
	{
	printf("%d -> ", starting_point);
	printf("%c", 'A' + path / 2);
	printf("\n");
	}
}
                
void print_ladder_game(int ladder_board[][MAX_COL], int people) {
	int i, j;

	for (i = 0; i < 12;i++) //이것과 이 아래의 코드들은 사다리 출력하는 함수인데, 배열에 저장되어있는 값에 따라 어떤 색깔의 사다리를 출력할지가 달라진다.
	{
		if (ladder_board[i][0] == 1)
			printf("+");
		else if (ladder_board[i][0] == 2 || ladder_board[i][0] == 7)
			printf(ORANGE "+" RESET);
		else if (ladder_board[i][0] == 3 || ladder_board[i][0] == 8)
			printf(GREEN "+" RESET);
		else if (ladder_board[i][0] == 4 || ladder_board[i][0] == 9)
			printf(YELLOW "+" RESET);
		else if (ladder_board[i][0] == 5 || ladder_board[i][0] == 10)
			printf(BLUE "+" RESET);
		else if (ladder_board[i][0] == 6 || ladder_board[i][0] == 11)
			printf(PURPLE "+" RESET);

		for (j = 0; j < people - 1;j++)
		{
			if (ladder_board[i][2 * j + 1] == 1)
				printf("--");
			else if ((ladder_board[i][2 * j + 1] == 2) || (ladder_board[i][2 * j + 1] == 7))
				printf(ORANGE "--" RESET);
			else if ((ladder_board[i][2 * j + 1] == 3) || (ladder_board[i][2 * j + 1] == 8))
				printf(GREEN "--" RESET);
			else if ((ladder_board[i][2 * j + 1] == 4) || (ladder_board[i][2 * j + 1] == 9))
				printf(YELLOW "--" RESET);
			else if ((ladder_board[i][2 * j + 1] == 5) || (ladder_board[i][2 * j + 1] == 10))
				printf(BLUE "--" RESET);
			else if ((ladder_board[i][2 * j + 1] == 6) || (ladder_board[i][2 * j + 1] == 11))
				printf(PURPLE "--" RESET); 
			else
				printf("  ");

			if (ladder_board[i][2 * (j + 1)] == 1)
				printf("+");
			else if ((ladder_board[i][2 * (j + 1)] == 2) || (ladder_board[i][2 * (j + 1)] == 7))
				printf(ORANGE "+" RESET);
			else if ((ladder_board[i][2 * (j + 1)] == 3) || (ladder_board[i][2 * (j + 1)] == 8))
				printf(GREEN "+" RESET);
			else if ((ladder_board[i][2 * (j + 1)] == 4) || (ladder_board[i][2 * (j + 1)] == 9))
				printf(YELLOW "+" RESET);
			else if ((ladder_board[i][2 * (j + 1)] == 5) || (ladder_board[i][2 * (j + 1)] == 10))
				printf(BLUE "+" RESET);
			else if ((ladder_board[i][2 * (j + 1)] == 6) || (ladder_board[i][2 * (j + 1)] == 11))
				printf(PURPLE "+" RESET);
		}
		printf("\n");
	}
	printf("\n");
}

void result_save(FILE* outfile, int ladder_board[][MAX_COL], int path, int starting_point, int people, int count) // 게임의 결과를 result.txt에 저장하는 함수
{
	int a = 11;

	fprintf(outfile, "%d %d\n", a, path);

	while (count != -1 && a > -1) //사다리 게임을 한다, a를 변화시키는 조건을 안 써도 되겠지?
	{
		if (path > 0 && ladder_board[a][path - 1] != 0)  // path왼쪽에 사다리가 있나 확인하는 작업.
		{
			ladder_board[a][path] = starting_point + 1;

		

			ladder_board[a][--path] = starting_point + 1; // --(가로줄)에 대한 이동

			fprintf(outfile, "%d %d\n", a, path);

			ladder_board[a][--path] = starting_point + 1; // --에 대한 이동 이후에 +(세로줄)로 도착
			fprintf(outfile, "%d %d\n", a, path);
			--a;
		}
		else if (path < 2 * (people - 1) && ladder_board[a][path + 1] != 0) // path오른쪽에 사다리가 있나 확인한다
		{
			ladder_board[a][path] = starting_point + 1;

			

			ladder_board[a][++path] = starting_point + 1; // 바로 위의 if문에 대한 내용과 같다고 보면 된다.

			fprintf(outfile, "%d %d\n", a, path);

			ladder_board[a][++path] = starting_point + 1;
			fprintf(outfile, "%d %d\n", a, path);
			--a;
		}
		else
		{
			ladder_board[a--][path] = starting_point + 1;
		}

		if (a != -1)
			fprintf(outfile, "%d %d\n", a, path);
	}

}
