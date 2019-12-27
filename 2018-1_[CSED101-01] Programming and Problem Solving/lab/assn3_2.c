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

	infile = fopen("map.txt", "r"); //������ �����ϴ� map.txt ������ ����.
	if (infile == NULL)
		printf("cannot open file.\n");

	fscanf(infile, "%d %d", &people, &garo); // txt������ �� ���� ����Ǿ��ִ� (������ ��, �������� ����)�� �о�´�. 
										

	outfile = fopen("result.txt", "w"); // ��ٸ� ������ ����� ������ result.txt ������ ���� ���� ����д�.
	if (outfile == NULL)
		printf("cannot open file");



	LoadLadder(ladder_board, people, infile); // ��Ȯ�� ��ǥ�� �԰��� ��ٸ��� �����.

	for (i = 0; i < people; i++)
		printf("%c  ", 'A' + i); // ������ ���
	printf("\n");

	print_ladder_game(ladder_board, people); // ��ٸ� ���

	for (i = 1; i <= people; i++) // ����� ���
		printf("%d  ", i);
	printf("\n");

         // �Ʒ��� ��� ������ �Է¹޾� �׿� ���� ��ٸ� ������ �����ϵ��� �ϴ� ���̴�.
	while (1) {                   
		int starting_point;
		printf(">> ");
		scanf("%d", &starting_point);
		FLUSH;


		int path;
		path = 2 * (starting_point - 1); // ��������� ��ٸ� ���� ��Ȯ�� ��ǥ�� ġȯ�ϴ� ����

		                               // �Ʒ��� �Է¹��� ���� 0�� �ƴϰ� -1�� �ƴ� ��, ������ �����Ѵٴ� ����
		if (starting_point != 0 && starting_point != -1) { 
			ladder_game(ladder_board, path, starting_point, people, count);
			count += 1;
		}
		else
		{
			if (starting_point == 0)  // 0�� �Է¹����� �ݺ����� Ż���Ͽ� ���α׷��� �����Ѵ�.
				break;
			else if (starting_point == -1) // -1�� �Է¹����� ��ٸ� ������ ��� ����� ���� ���� ���� ������� ����Ѵ�.
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

int LoadLadder(int ladder_board[][MAX_COL], int people, FILE* infile) //map.txt�κ��� �Է¹��� ���� ���� ��Ȯ�� ��ٸ� ���� ����� �����̴�. ��ٸ��� ���� �κп� 0�� �����Ѵ�.
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
		for (i = 0;i < 12;i++) // ������ �׷����� ������ �κ� �׸���
		{
			for (j = 1;j <= people;j++)
				ladder_board[i][2 * j - 2] = 1;
		}

		while (fscanf(input, "%d %d", &temp1, &temp2) != EOF) //������ �׸���
		{
			ladder_board[temp1][2 * (temp2)-1] = 1;
		}

		for (i = 0;i < 12;i++) //��ٸ��� �� �׷����� ������ 2�� for������ 0�� �����Ѵ�.
		{
			for (j = 0;j <= people;j++)
			{
				if (ladder_board[i][2 * j + 1] == 1)
				{
					continue; // 1�� ����Ǿ� ������ �Ʒ��� 0�� �����ϴ� �ܰ踦 �ǳʶٰ� 1�� ����� ä�� ����д�.
				}
				ladder_board[i][2 * j + 1] = 0;
			}
		}

		fclose(input);

		return 1;  
	}

}

void ladder_game(int ladder_board[][MAX_COL], int path, int starting_point, int people, int count) // ��ٸ� ������ �����ϴ� �Լ��̴�. ������ �����ϸ� ��ٸ��� �Բ� ����Ѵ�.
{
	int i,a = 11;
	int p;

	while (count != -1 && a > -1) //��ٸ� ������ �ϰ� ��µ� �Ѵ�. count�� -1�� �ƴ� ���� ������ �����ϰ� ��µ� �Ѵ�.
	{
		if (path > 0 && ladder_board[a][path - 1] != 0)  // path���ʿ� ��ٸ��� �ֳ� Ȯ���ϴ� �۾�.
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

			ladder_board[a][--path] = starting_point + 1; // --(������)�� ���� �̵�

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

			ladder_board[a][--path] = starting_point + 1; // --�� ���� �̵� ���Ŀ� +(������)�� ����
			--a;
		}
		else if (path < 2 * (people - 1) && ladder_board[a][path + 1] != 0) // path�� ������ �����̾�� �� �ǰ���?, path�����ʿ� ��ٸ��� �ֳ� Ȯ���Ѵ�
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

			ladder_board[a][++path] = starting_point + 1; // �ٷ� ���� if���� ���� ����� ���ٰ� ���� �ȴ�.

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
    

	while (count == -1 && a > -1) //count�� -1�� ������ ��ٸ� ������ �ϴµ� ��ٸ��� ����� ������ �ʰ� ������ ������� �����س���.
	{
		if (path > 0 && ladder_board[a][path - 1] != 0)  // path���ʿ� ��ٸ��� �ֳ� Ȯ���ϴ� �۾�.
		{
			ladder_board[a][path] = starting_point + 1;
			ladder_board[a][--path] = starting_point + 1; // --(������)�� ���� �̵�
			ladder_board[a][--path] = starting_point + 1; // --�� ���� �̵� ���Ŀ� +(������)�� ����
			--a;
		}
		else if (path < 2 * (people - 1) && ladder_board[a][path + 1] != 0) // path�����ʿ� ��ٸ��� �ֳ� Ȯ���Ѵ�
		{
			ladder_board[a][path] = starting_point + 1;
			ladder_board[a][++path] = starting_point + 1; // �ٷ� ���� if���� ���� ����� ���ٰ� ���� �ȴ�.
			ladder_board[a][++path] = starting_point + 1;
			--a;
		}
		else
		{
			ladder_board[a--][path] = starting_point + 1;
		}
	}

	if (count != -1) // �ϳ��� ������ ������ �� ��� ���
	{
	printf("result: %d -> ", starting_point); 
	printf("%c", 'A' + path / 2);
	printf("\n");
	}
	else // ��� ����� ���� ���� ������  ����� ����ؾ��ϴ� ���
	{
	printf("%d -> ", starting_point);
	printf("%c", 'A' + path / 2);
	printf("\n");
	}
}
                
void print_ladder_game(int ladder_board[][MAX_COL], int people) {
	int i, j;

	for (i = 0; i < 12;i++) //�̰Ͱ� �� �Ʒ��� �ڵ���� ��ٸ� ����ϴ� �Լ��ε�, �迭�� ����Ǿ��ִ� ���� ���� � ������ ��ٸ��� ��������� �޶�����.
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

void result_save(FILE* outfile, int ladder_board[][MAX_COL], int path, int starting_point, int people, int count) // ������ ����� result.txt�� �����ϴ� �Լ�
{
	int a = 11;

	fprintf(outfile, "%d %d\n", a, path);

	while (count != -1 && a > -1) //��ٸ� ������ �Ѵ�, a�� ��ȭ��Ű�� ������ �� �ᵵ �ǰ���?
	{
		if (path > 0 && ladder_board[a][path - 1] != 0)  // path���ʿ� ��ٸ��� �ֳ� Ȯ���ϴ� �۾�.
		{
			ladder_board[a][path] = starting_point + 1;

		

			ladder_board[a][--path] = starting_point + 1; // --(������)�� ���� �̵�

			fprintf(outfile, "%d %d\n", a, path);

			ladder_board[a][--path] = starting_point + 1; // --�� ���� �̵� ���Ŀ� +(������)�� ����
			fprintf(outfile, "%d %d\n", a, path);
			--a;
		}
		else if (path < 2 * (people - 1) && ladder_board[a][path + 1] != 0) // path�����ʿ� ��ٸ��� �ֳ� Ȯ���Ѵ�
		{
			ladder_board[a][path] = starting_point + 1;

			

			ladder_board[a][++path] = starting_point + 1; // �ٷ� ���� if���� ���� ����� ���ٰ� ���� �ȴ�.

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
