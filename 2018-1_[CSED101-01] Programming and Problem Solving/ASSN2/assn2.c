#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int show_menu();
void draw_line();
int game_start();
void show_record(int win, int lose);
void generate_two_numbers(int *n1, int *n2);
int win_lose_draw(int player_num, int com_num);
int print_stairs(int stair, int pposi, int cposi);
void print_RPS(int play1, int play2);
void num_select(int *play1, int *play2);
void print_select(int play1, int play2);
int what_win(int player_final);
int game_quit_yes();


int main()
{
	srand(time(NULL)); //컴퓨터가 랜덤하게 숫자를 고르도록 하기 위해서 이용
	show_menu();

	return 0;
}

int show_menu() // 초기 메뉴 창을 띄워주는 함수
{
	
	int win = 0, lose = 0;
	while (1) {
		system("cls");
		draw_line();
		printf("                             1. 게임 시작                        \n");
		printf("\n");
		printf("                             2. 전적 및 승률                     \n");
		printf("\n");
		printf("                             3. 게임 종료                        \n");
		printf("\n");
		draw_line();

		printf("메뉴 번호 입력 >> ");
		
		int input_num;
		scanf("%d", &input_num);

		char yesNo;
		switch (input_num)
		{
		case 1:
			if (game_start() == 1) // 승리했을 때
			{
				win = win + 1;
			}
			else // 패배했을 때
			{
				lose = lose + 1;
			}
			system("pause");
			break;
		case 2:
			show_record(win, lose);
			break;
		case 3:
			printf("게임을 종료하시겠습니까?(y/n)");
			scanf("%*c%c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y')
			{
				printf("게임을 종료합니다...\n"); 
				return input_num;
			}
			break;
		}
	}
}

void draw_line() // ▩기호로 선을 그리는 함수
{
	int i;
	for (i = 1; i <= 40; i++)
	{
		printf("▩");
	}
	printf("\n");
	printf("\n");
}

int game_start()  //내가 이기면 1 리턴 컴퓨터가 이기면 -1 리턴
{
	system("cls");
	int stair;
	int checkpoint = 1;
	while (checkpoint)
	{
		printf("게임을 위한 계단의 개수를 입력(10~30) >> ");
		scanf("%*c%d", &stair);
		printf("\n");

		if (stair >= 10 && stair <= 30)
			checkpoint = 0;
	}
	system("cls");

	int pposi = 0;
	int cposi = stair; //pposi는 플레이어 가로 좌표, cposi는 컴퓨터 가로 좌표
	int player1 = 0, player2 = 0, player_final=0, com_final=0;
	int n1, n2;
	int result = 0;
	char yesno;

	while (1)
	{
		if (result == 1) 
		{
			pposi = pposi + what_win(player_final);  //가위바위보 중에서 뭐로 이겼느냐에 따라 다른 칸 수를 이동한다(플레이어)
		}
		else if (result == -1)
		{
			cposi = cposi - what_win(com_final); //가위바위보 중에서 뭐로 이겼느냐에 따라 다른 칸 수를 이동한다(컴퓨터)
		}
		system("cls");

		printf("총 계단수: %d\n", stair);
		printf("PLAYER :   ○ <%d>\n", pposi);
		printf("COMPUTER : ● <%d>\n", stair - cposi);

		print_stairs(stair, pposi, cposi); //계단 개수와 플레이어, 컴퓨터의 가로 좌표를 받아서 계단 출력
		printf("가위<1>, 바위<2>, 보<3> >> ");

		if (pposi >= stair || cposi <= 0)
			break;
		num_select(&player1, &player2); // 플레이어가 입력한 2개의 숫자를 player1이랑 player2에 하나씩 저장한다 서로 다르게

		generate_two_numbers(&n1, &n2); // 컴퓨터가 2개 고름

		printf("[컴퓨터의 후보]\n");
		printf("\n");
		print_RPS(n1, n2); // 가위바위보 중 고른 2개
		printf("\n");
		printf("[플레이어의 후보]\n");
		printf("\n");
		print_RPS(player1, player2); // 가위바위보 중 고른 2개

		print_select(player1, player2);  // 가위, 바위, 보 중에서 선택한 두 가지가 무엇인지 출력해준다.

		while (1) // 플레이어가 숫자 2개 중에서 하나를 고르게 하는 것, 골라서 player_final에 넣는다.
		{
			scanf("%*c%d", &player_final);
			if (player_final == player1 || player_final == player2) //입력한 숫자가 처음 고른 2개 중에 있으면 break
				break;
			else if (player_final == 0) // 하나 빼기 일 단계에서 0을 입력하면 게임을 중도포기하는 내용
			{
				if (game_quit_yes() == 1)
				{
					return -1;
				}
				else
				{
					print_select(player1, player2);  // 가위, 바위, 보 중에서 선택한 두 가지가 무엇인지 출력해준다.
				}
			}
			else
				printf("잘못된 입력입니다. 다시 선택하세요.\n");
			//print_select(player1, player2);

		}

		com_final = com_select(n1, n2, player1, player2); //컴퓨터의 하나 빼기 일

		printf("[컴퓨터 최종 선택]\n");
		if (com_final == 1) // 컴퓨터 최종 선택에 따라 가위 바위 보 중에서 하나 출력
		{
			print_scissors();
		}
		else if (com_final == 2)
		{
			print_rock();
		}
		else if (com_final == 3)
		{
			print_paper();
		}

		printf("[플레이어 최종 선택]\n");
		if (player_final == 1)  // 플레이어 최종 선택에 따라 가위 바위 보 중에서 하나 출력
		{
			print_scissors();
		}
		else if (player_final == 2)
		{
			print_rock();
		}
		else if (player_final == 3)
		{
			print_paper();
		}

		result = win_lose_draw(player_final, com_final); //플레이어가 승리하면 1 패배하면 -1 비기면 0 리턴
		if (result == 1) {
			printf("플레이어가 이겼습니다!!\n");
		}
		else if (result == -1) {
			printf("컴퓨터가 이겼습니다!!\n");
		}
		else
			printf("비겼습니다!!\n");

		printf("\n");
		printf("계속 하려면 엔터키를 입력하세요...\n");
		system("pause");

	}

		if (pposi >= stair) // 플레이어가 최종 승리할 때
		{
			pposi = stair;
			system("cls");

			printf("총 계단수: %d\n", stair);
			printf("PLAYER :   ○ <%d>\n", pposi);
			printf("COMPUTER : ● <%d>\n", stair - cposi);
			print_stairs(stair, pposi, cposi);
			printf("\n");
			draw_line();
			printf("\n");
			printf("★ ★ 플레이어의 최종 승리 ★ ★\n");
			printf("\n");
			draw_line();
			printf("메뉴로 돌아가려면 엔터키를 입력하세요...\n");

			return 1; //내가 이기면 1 리턴
		}
		else // 컴퓨터가 최종 승리할 때
		{
			cposi = 0;
			system("cls");

			printf("총 계단수: %d\n", stair);
			printf("PLAYER :   ○ <%d>\n", pposi);
			printf("COMPUTER : ● <%d>\n", stair - cposi);
			print_stairs(stair, pposi, cposi);
			printf("\n");
			draw_line();
			printf("\n");
			printf("★ ★ 컴퓨터의 최종 승리 ★ ★\n");
			printf("\n");
			draw_line();
			printf("메뉴로 돌아가려면 엔터키를 입력하세요...\n");

			return -1; //내가 지면 -1 리턴
		}
}

int print_stairs(int stair, int pposi, int cposi) // 계단, 플레이어 가로좌표, 컴퓨터 가로좌표를 이용해 계단 출력
{

	if (stair >= 10 && stair <= 30)   // 계단 개수가 10~30이라면 실행한다 
	{
		printf("\n");
		int a, b, c;


		for (a = 0; a <= (stair / 2 + stair % 2); a++)  // a에 의해 세로 칸 수 결정
		{
			for (b = 0; b < a; b++)
			{
				printf("▩");
			}
			for (b = 0; b <= stair - 2 * a; b++)
			{
				if (b == 0)
				{
					if (pposi == cposi && pposi == a)  // 위치 같을 때 
						printf("◑");
					else
					{
						if (pposi != a && cposi != a)  // 동그라미가 없는 곳에 공백
							printf("  ");
						else if (pposi == a) // 플레이어 동그라미
							printf("○");
						else if (cposi == a) // 컴퓨터 동그라미
							printf("●");
					}
				}
				else if (b == stair - 2 * a)
				{
					if (pposi == cposi && pposi == stair - a) // 위치 같을 때
						printf("◑");
					else
					{
						if (pposi != stair - a && cposi != stair - a) // 동그라미 없는 곳에 공백
							printf("  ");
						else if (pposi == stair - a) // 플레이어 동그라미
							printf("○");
						else if (cposi == stair - a) // 컴퓨터 동그라미
							printf("●");
					}
				}
				else
					printf("  ");

			}
			for (c = 0; c < a; c++)
			{
				printf("▩");
			}
			printf("\n");
		}

	}


	


}

print_rock_scissors() //바위와 가위 그림 출력
{
	printf(" ──────────────────────────────────────────────────\n");
	printf("│                        ││                        │\n");
	printf("│        ▩▩▩▩        ││           ▩▩         │\n");
	printf("│    ▩▩▩▩▩▩▩▩    ││        ▩▩            │\n");
	printf("│  ▩▩▩▩▩▩▩▩▩▩  ││     ▩▩               │\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ ││  ▩▩▩▩▩▩▩▩▩▩▩│\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ ││ ▩▩▩▩▩▩           │\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ ││ ▩▩▩▩▩▩▩         │\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ ││ ▩▩▩▩▩▩▩         │\n");
	printf("│  ▩▩▩▩▩▩▩▩▩▩  ││ ▩▩▩▩▩▩           │\n");
	printf("│   ▩▩▩▩▩▩▩▩▩   ││ ▩▩▩▩▩             │\n");
	printf("│     ▩▩▩▩▩▩▩     ││ ▩▩▩                 │\n");
	printf("│                        ││                        │\n");
	printf(" ──────────────────────────────────────────────────\n");
}

print_paper_rock() //보자기와 바위 그림 출력
{
	printf(" ──────────────────────────────────────────────────\n");
	printf("│                        ││                        │\n");
	printf("│      ▩▩▩▩▩        ││         ▩▩▩▩       │\n");
	printf("│    ▩▩▩▩            ││     ▩▩▩▩▩▩▩▩   │\n");
	printf("│  ▩▩▩▩▩▩▩▩▩▩  ││   ▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│ ▩▩▩▩▩▩▩         ││  ▩▩▩▩▩▩▩▩▩▩▩│\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ ││  ▩▩▩▩▩▩▩▩▩▩▩│\n");
	printf("│ ▩▩▩▩▩▩▩         ││  ▩▩▩▩▩▩▩▩▩▩▩│\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ ││  ▩▩▩▩▩▩▩▩▩▩▩│\n");
	printf("│  ▩▩▩▩▩▩          ││   ▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│   ▩▩▩▩▩▩▩▩     ││    ▩▩▩▩▩▩▩▩▩  │\n");
	printf("│      ▩▩▩            ││      ▩▩▩▩▩▩▩    │\n");
	printf("│                        ││                        │\n");
	printf(" ──────────────────────────────────────────────────\n");
}

print_scissors_paper() //가위와 보자기 그림 출력
{
	printf(" ──────────────────────────────────────────────────\n");
	printf("│                        ││                        │\n");
	printf("│           ▩▩         ││       ▩▩▩▩▩       │\n");
	printf("│        ▩▩            ││     ▩▩▩▩           │\n");
	printf("│     ▩▩               ││   ▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│  ▩▩▩▩▩▩▩▩▩▩▩││  ▩▩▩▩▩▩▩        │\n");
	printf("│ ▩▩▩▩▩▩           ││  ▩▩▩▩▩▩▩▩▩▩▩│\n");
	printf("│ ▩▩▩▩▩▩▩         ││  ▩▩▩▩▩▩▩        │\n");
	printf("│ ▩▩▩▩▩▩▩         ││  ▩▩▩▩▩▩▩▩▩▩▩│\n");
	printf("│ ▩▩▩▩▩▩           ││   ▩▩▩▩▩▩         │\n");
	printf("│ ▩▩▩▩▩             ││    ▩▩▩▩▩▩▩▩    │\n");
	printf("│  ▩▩▩                ││      ▩▩▩            │\n");
	printf("│                        ││                        │\n");
	printf(" ──────────────────────────────────────────────────\n");
}

print_scissors() // 가위 출력
{
	printf(" ───────────────────────\n");
	printf("│                        │\n");
	printf("│          ▩▩          │\n");
	printf("│       ▩▩             │\n");
	printf("│    ▩▩                │\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│▩▩▩▩▩▩            │\n");
	printf("│▩▩▩▩▩▩▩          │\n");
	printf("│▩▩▩▩▩▩▩          │\n");
	printf("│▩▩▩▩▩▩            │\n");
	printf("│▩▩▩▩▩              │\n");
	printf("│ ▩▩▩                 │\n");
	printf("│                        │\n");
	printf(" ───────────────────────\n");
}

print_rock() // 바위 출력
{
	printf(" ───────────────────────\n");
	printf("│                        │\n");
	printf("│         ▩▩▩▩       │\n");
	printf("│     ▩▩▩▩▩▩▩▩   │\n");
	printf("│   ▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│  ▩▩▩▩▩▩▩▩▩▩  │\n");
	printf("│   ▩▩▩▩▩▩▩▩▩   │\n");
	printf("│     ▩▩▩▩▩▩▩     │\n");
	printf("│                        │\n");
	printf(" ───────────────────────\n");
}

print_paper() // 보자기 출력
{
	printf(" ───────────────────────\n");
	printf("│                        │\n");
	printf("│      ▩▩▩▩▩        │\n");
	printf("│    ▩▩▩▩            │\n");
	printf("│  ▩▩▩▩▩▩▩▩▩▩  │\n");
	printf("│ ▩▩▩▩▩▩▩         │\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│ ▩▩▩▩▩▩▩         │\n");
	printf("│ ▩▩▩▩▩▩▩▩▩▩▩ │\n");
	printf("│  ▩▩▩▩▩▩          │\n");
	printf("│   ▩▩▩▩▩▩▩▩     │\n");
	printf("│     ▩▩▩             │\n");
	printf("│                        │\n");
	printf(" ───────────────────────\n");
}

void generate_two_numbers(int *n1, int *n2) // 컴퓨터가 1,2,3 중에서 랜덤하게 2개의 서로 다른 숫자를 고르게 하기
{
	*n1 = rand() % 3 + 1;
	*n2 = rand() % 3 + 1;
		while(*n2 == *n1)
		{
			*n2 = rand() % 3 + 1;
		}
}

void show_record(int win, int lose) // 전적을 보여주는 함수
{
	if (win == 0 && lose == 0) // 승,패 둘다 0일 때
	{
		system("cls");
		draw_line();
		printf("\n");
		printf("                승리:  0\n");
		printf("\n");
		printf("                패배:  0\n");
		printf("\n");
		printf("                승률:  0.00%% \n");
		printf("\n");
		draw_line();
		printf("\n");
		printf("메뉴로 돌아가려면 엔터키를 입력하세요...\n");
		printf("\n");
	}
	else
	{
		system("cls");
		draw_line();
		printf("\n");
		printf("                승리:  %d\n", win);
		printf("\n");
		printf("                패배:  %d\n", lose);
		printf("\n");
		printf("                승률:  %.2f%% \n", win * 100.00 / (win + lose)); // 승률 계산인데 원래 인트형인 변수를 소수로 계산하기 위해 100.00이라 씀
		printf("\n");
		draw_line();
		printf("\n");
		printf("메뉴로 돌아가려면 엔터키를 입력하세요...\n");
		printf("\n");
	}
	system("pause");
}

int win_lose_draw(int player_num, int com_num)  // 가위 바위 보의 승패를 결정하는 함수, 승리 1, 패배 -1, 비김 0 리턴
{


	if (player_num == 1 && com_num == 3) //난 가위 컴퓨터 보 (승)
	{
		return 1;
	}
	if (player_num == 2 && com_num == 1) //난 바위 컴퓨터 가위 (승)
	{
		return 1;
	}
	if (player_num == 3 && com_num == 2) //난 보 컴퓨터 바위 (승)
	{
		return 1;
	}
	if (player_num == 1 && com_num == 2) //난 가위 컴퓨터 바위 (패)
	{
		return -1;
	}
	if (player_num == 2 && com_num == 3) //난 바위 컴퓨터 보 (패)
	{
		return -1;
	}
	if (player_num == 3 && com_num == 1) //난 보 컴퓨터 가위 (패)
	{
		return -1;
	}
	if (player_num == com_num) // 비겼을 때
	{
		return 0;
	}
}

void print_RPS(int play1, int play2)   // 선택된 숫자 2개에 따라 가위 바위 보 중에서 2개를 한 번에 출력
{
	if (play1 == 1 && play2 == 2)
	{
		print_rock_scissors();

	}
	else if (play1 == 1 && play2 == 3)
	{
		print_scissors_paper();
		
	}
	else if (play1 == 2 && play2 == 1)
	{
		print_rock_scissors();
		
	}
	else if (play1 == 2 && play2 == 3)
	{
		print_paper_rock();
		
	}
	else if (play1 == 3 && play2 == 1)
	{
		print_scissors_paper();
		
	}
	else if (play1 == 3 && play2 == 2)
	{
		print_paper_rock();
		
	}
}

void print_select(int play1, int play2) // 고른 2개의 숫자를 토대로 뭘 골랐는지 출력 
{
	if (play1 == 1 && play2 == 2)
		printf("바위<2>, 가위<1> >>\n");
	else if (play1 == 1 && play2 == 3)
		printf("가위<1>, 보<3> >>\n");
	else if (play1 == 2 && play2 == 1)
		printf("바위<2>, 가위<1> >>\n");
	else if (play1 == 2 && play2 == 3)
		printf("보<3>, 바위<2> >>\n");
	else if (play1 == 3 && play2 == 1)
		printf("가위<1>, 보<3> >>\n");
	else if (play1 == 3 && play2 == 2)
		printf("보<3>, 바위<2> >>\n");
}

void num_select(int *play1, int *play2) // 플레이어가 입력한 2개의 숫자를 play1이랑 play2에 하나씩 저장한다. 그리고 1,2,3 중에서 서로 다른 2개의 숫자를 뽑도록 한다.
{
	while (1)
	{
		scanf(" %d %d", play1, play2);
		if (*play1 != *play2 && *play1 <=3 && *play1 >=1 && *play2 <= 3 && *play2 >= 1)
		{
			break;
		}
		printf("가위<1>, 바위<2>, 보<3> >> ");
	}
}

int com_select(int n1, int n2, int play1, int play2) // n1과 n2는 컴퓨터숫자 play1과 play2는 내 숫자이다. 플레이어와 컴퓨터가 서로 같은 2개를 냈을 때 컴퓨터가 이기는 쪽을 하나 빼기 일 하도록 하는 함수
{
	int n = rand() % 2;
	int decide = 0;

	if ((n1 == play1 && n2 == play2) || (n1 == play2 && n2 == play1))
	{
		if ((n1 == 1 && n2 == 2) || (n1 == 2 && n2 == 1))
			decide = 2;
		else if ((n1 == 1 && n2 == 3) || (n1 == 3 && n2 == 1))
			decide = 1;
		else if ((n1 == 2 && n2 == 3) || (n1 == 3 && n2 == 2))
			decide = 3;
	}
	else if (n == 0)
		decide = n1;
	else if (n == 1)
		decide = n2;

	return decide;
}

int what_win(int player_final) // 가위 바위 보 중에서 무엇으로 이겼느냐에 따라 리턴 값을 다르게 해서 이동하는 칸 수를 조절한다.
{
	if (player_final == 1)
	{
		return 1;
	}
	if (player_final == 2)
	{
		return 2;
	}
	if (player_final == 3)
	{
		return 3;
	}
}

int game_quit_yes() //게임을 도중 포기하는 경우에 대한 함수, Y 혹은 y를 누르면 1리턴, N 혹은 n을 누르면 0 리턴
{
	char yesno; 

	printf("이번 게임을 포기하시겠습니까?(y/n)");
	scanf("%*c%c", &yesno);

	if (yesno == 'y' || yesno == 'Y')
	{
		return 1;
	}
	else if (yesno == 'n' || yesno == 'N')
	{
		return 0;
	}
}