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
	srand(time(NULL)); //��ǻ�Ͱ� �����ϰ� ���ڸ� ������ �ϱ� ���ؼ� �̿�
	show_menu();

	return 0;
}

int show_menu() // �ʱ� �޴� â�� ����ִ� �Լ�
{
	
	int win = 0, lose = 0;
	while (1) {
		system("cls");
		draw_line();
		printf("                             1. ���� ����                        \n");
		printf("\n");
		printf("                             2. ���� �� �·�                     \n");
		printf("\n");
		printf("                             3. ���� ����                        \n");
		printf("\n");
		draw_line();

		printf("�޴� ��ȣ �Է� >> ");
		
		int input_num;
		scanf("%d", &input_num);

		char yesNo;
		switch (input_num)
		{
		case 1:
			if (game_start() == 1) // �¸����� ��
			{
				win = win + 1;
			}
			else // �й����� ��
			{
				lose = lose + 1;
			}
			system("pause");
			break;
		case 2:
			show_record(win, lose);
			break;
		case 3:
			printf("������ �����Ͻðڽ��ϱ�?(y/n)");
			scanf("%*c%c", &yesNo);
			if (yesNo == 'y' || yesNo == 'Y')
			{
				printf("������ �����մϴ�...\n"); 
				return input_num;
			}
			break;
		}
	}
}

void draw_line() // �̱�ȣ�� ���� �׸��� �Լ�
{
	int i;
	for (i = 1; i <= 40; i++)
	{
		printf("��");
	}
	printf("\n");
	printf("\n");
}

int game_start()  //���� �̱�� 1 ���� ��ǻ�Ͱ� �̱�� -1 ����
{
	system("cls");
	int stair;
	int checkpoint = 1;
	while (checkpoint)
	{
		printf("������ ���� ����� ������ �Է�(10~30) >> ");
		scanf("%*c%d", &stair);
		printf("\n");

		if (stair >= 10 && stair <= 30)
			checkpoint = 0;
	}
	system("cls");

	int pposi = 0;
	int cposi = stair; //pposi�� �÷��̾� ���� ��ǥ, cposi�� ��ǻ�� ���� ��ǥ
	int player1 = 0, player2 = 0, player_final=0, com_final=0;
	int n1, n2;
	int result = 0;
	char yesno;

	while (1)
	{
		if (result == 1) 
		{
			pposi = pposi + what_win(player_final);  //���������� �߿��� ���� �̰���Ŀ� ���� �ٸ� ĭ ���� �̵��Ѵ�(�÷��̾�)
		}
		else if (result == -1)
		{
			cposi = cposi - what_win(com_final); //���������� �߿��� ���� �̰���Ŀ� ���� �ٸ� ĭ ���� �̵��Ѵ�(��ǻ��)
		}
		system("cls");

		printf("�� ��ܼ�: %d\n", stair);
		printf("PLAYER :   �� <%d>\n", pposi);
		printf("COMPUTER : �� <%d>\n", stair - cposi);

		print_stairs(stair, pposi, cposi); //��� ������ �÷��̾�, ��ǻ���� ���� ��ǥ�� �޾Ƽ� ��� ���
		printf("����<1>, ����<2>, ��<3> >> ");

		if (pposi >= stair || cposi <= 0)
			break;
		num_select(&player1, &player2); // �÷��̾ �Է��� 2���� ���ڸ� player1�̶� player2�� �ϳ��� �����Ѵ� ���� �ٸ���

		generate_two_numbers(&n1, &n2); // ��ǻ�Ͱ� 2�� ��

		printf("[��ǻ���� �ĺ�]\n");
		printf("\n");
		print_RPS(n1, n2); // ���������� �� �� 2��
		printf("\n");
		printf("[�÷��̾��� �ĺ�]\n");
		printf("\n");
		print_RPS(player1, player2); // ���������� �� �� 2��

		print_select(player1, player2);  // ����, ����, �� �߿��� ������ �� ������ �������� ������ش�.

		while (1) // �÷��̾ ���� 2�� �߿��� �ϳ��� ���� �ϴ� ��, ��� player_final�� �ִ´�.
		{
			scanf("%*c%d", &player_final);
			if (player_final == player1 || player_final == player2) //�Է��� ���ڰ� ó�� �� 2�� �߿� ������ break
				break;
			else if (player_final == 0) // �ϳ� ���� �� �ܰ迡�� 0�� �Է��ϸ� ������ �ߵ������ϴ� ����
			{
				if (game_quit_yes() == 1)
				{
					return -1;
				}
				else
				{
					print_select(player1, player2);  // ����, ����, �� �߿��� ������ �� ������ �������� ������ش�.
				}
			}
			else
				printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
			//print_select(player1, player2);

		}

		com_final = com_select(n1, n2, player1, player2); //��ǻ���� �ϳ� ���� ��

		printf("[��ǻ�� ���� ����]\n");
		if (com_final == 1) // ��ǻ�� ���� ���ÿ� ���� ���� ���� �� �߿��� �ϳ� ���
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

		printf("[�÷��̾� ���� ����]\n");
		if (player_final == 1)  // �÷��̾� ���� ���ÿ� ���� ���� ���� �� �߿��� �ϳ� ���
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

		result = win_lose_draw(player_final, com_final); //�÷��̾ �¸��ϸ� 1 �й��ϸ� -1 ���� 0 ����
		if (result == 1) {
			printf("�÷��̾ �̰���ϴ�!!\n");
		}
		else if (result == -1) {
			printf("��ǻ�Ͱ� �̰���ϴ�!!\n");
		}
		else
			printf("�����ϴ�!!\n");

		printf("\n");
		printf("��� �Ϸ��� ����Ű�� �Է��ϼ���...\n");
		system("pause");

	}

		if (pposi >= stair) // �÷��̾ ���� �¸��� ��
		{
			pposi = stair;
			system("cls");

			printf("�� ��ܼ�: %d\n", stair);
			printf("PLAYER :   �� <%d>\n", pposi);
			printf("COMPUTER : �� <%d>\n", stair - cposi);
			print_stairs(stair, pposi, cposi);
			printf("\n");
			draw_line();
			printf("\n");
			printf("�� �� �÷��̾��� ���� �¸� �� ��\n");
			printf("\n");
			draw_line();
			printf("�޴��� ���ư����� ����Ű�� �Է��ϼ���...\n");

			return 1; //���� �̱�� 1 ����
		}
		else // ��ǻ�Ͱ� ���� �¸��� ��
		{
			cposi = 0;
			system("cls");

			printf("�� ��ܼ�: %d\n", stair);
			printf("PLAYER :   �� <%d>\n", pposi);
			printf("COMPUTER : �� <%d>\n", stair - cposi);
			print_stairs(stair, pposi, cposi);
			printf("\n");
			draw_line();
			printf("\n");
			printf("�� �� ��ǻ���� ���� �¸� �� ��\n");
			printf("\n");
			draw_line();
			printf("�޴��� ���ư����� ����Ű�� �Է��ϼ���...\n");

			return -1; //���� ���� -1 ����
		}
}

int print_stairs(int stair, int pposi, int cposi) // ���, �÷��̾� ������ǥ, ��ǻ�� ������ǥ�� �̿��� ��� ���
{

	if (stair >= 10 && stair <= 30)   // ��� ������ 10~30�̶�� �����Ѵ� 
	{
		printf("\n");
		int a, b, c;


		for (a = 0; a <= (stair / 2 + stair % 2); a++)  // a�� ���� ���� ĭ �� ����
		{
			for (b = 0; b < a; b++)
			{
				printf("��");
			}
			for (b = 0; b <= stair - 2 * a; b++)
			{
				if (b == 0)
				{
					if (pposi == cposi && pposi == a)  // ��ġ ���� �� 
						printf("��");
					else
					{
						if (pposi != a && cposi != a)  // ���׶�̰� ���� ���� ����
							printf("  ");
						else if (pposi == a) // �÷��̾� ���׶��
							printf("��");
						else if (cposi == a) // ��ǻ�� ���׶��
							printf("��");
					}
				}
				else if (b == stair - 2 * a)
				{
					if (pposi == cposi && pposi == stair - a) // ��ġ ���� ��
						printf("��");
					else
					{
						if (pposi != stair - a && cposi != stair - a) // ���׶�� ���� ���� ����
							printf("  ");
						else if (pposi == stair - a) // �÷��̾� ���׶��
							printf("��");
						else if (cposi == stair - a) // ��ǻ�� ���׶��
							printf("��");
					}
				}
				else
					printf("  ");

			}
			for (c = 0; c < a; c++)
			{
				printf("��");
			}
			printf("\n");
		}

	}


	


}

print_rock_scissors() //������ ���� �׸� ���
{
	printf(" ����������������������������������������������������������������������������������������������������\n");
	printf("��                        ����                        ��\n");
	printf("��        �̢̢̢�        ����           �̢�         ��\n");
	printf("��    �̢̢̢̢̢̢̢�    ����        �̢�            ��\n");
	printf("��  �̢̢̢̢̢̢̢̢̢�  ����     �̢�               ��\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ����  �̢̢̢̢̢̢̢̢̢̢̦�\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ���� �̢̢̢̢̢�           ��\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ���� �̢̢̢̢̢̢�         ��\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ���� �̢̢̢̢̢̢�         ��\n");
	printf("��  �̢̢̢̢̢̢̢̢̢�  ���� �̢̢̢̢̢�           ��\n");
	printf("��   �̢̢̢̢̢̢̢̢�   ���� �̢̢̢̢�             ��\n");
	printf("��     �̢̢̢̢̢̢�     ���� �̢̢�                 ��\n");
	printf("��                        ����                        ��\n");
	printf(" ����������������������������������������������������������������������������������������������������\n");
}

print_paper_rock() //���ڱ�� ���� �׸� ���
{
	printf(" ����������������������������������������������������������������������������������������������������\n");
	printf("��                        ����                        ��\n");
	printf("��      �̢̢̢̢�        ����         �̢̢̢�       ��\n");
	printf("��    �̢̢̢�            ����     �̢̢̢̢̢̢̢�   ��\n");
	printf("��  �̢̢̢̢̢̢̢̢̢�  ����   �̢̢̢̢̢̢̢̢̢� ��\n");
	printf("�� �̢̢̢̢̢̢�         ����  �̢̢̢̢̢̢̢̢̢̢̦�\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ����  �̢̢̢̢̢̢̢̢̢̢̦�\n");
	printf("�� �̢̢̢̢̢̢�         ����  �̢̢̢̢̢̢̢̢̢̢̦�\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ����  �̢̢̢̢̢̢̢̢̢̢̦�\n");
	printf("��  �̢̢̢̢̢�          ����   �̢̢̢̢̢̢̢̢̢� ��\n");
	printf("��   �̢̢̢̢̢̢̢�     ����    �̢̢̢̢̢̢̢̢�  ��\n");
	printf("��      �̢̢�            ����      �̢̢̢̢̢̢�    ��\n");
	printf("��                        ����                        ��\n");
	printf(" ����������������������������������������������������������������������������������������������������\n");
}

print_scissors_paper() //������ ���ڱ� �׸� ���
{
	printf(" ����������������������������������������������������������������������������������������������������\n");
	printf("��                        ����                        ��\n");
	printf("��           �̢�         ����       �̢̢̢̢�       ��\n");
	printf("��        �̢�            ����     �̢̢̢�           ��\n");
	printf("��     �̢�               ����   �̢̢̢̢̢̢̢̢̢� ��\n");
	printf("��  �̢̢̢̢̢̢̢̢̢̢̦���  �̢̢̢̢̢̢�        ��\n");
	printf("�� �̢̢̢̢̢�           ����  �̢̢̢̢̢̢̢̢̢̢̦�\n");
	printf("�� �̢̢̢̢̢̢�         ����  �̢̢̢̢̢̢�        ��\n");
	printf("�� �̢̢̢̢̢̢�         ����  �̢̢̢̢̢̢̢̢̢̢̦�\n");
	printf("�� �̢̢̢̢̢�           ����   �̢̢̢̢̢�         ��\n");
	printf("�� �̢̢̢̢�             ����    �̢̢̢̢̢̢̢�    ��\n");
	printf("��  �̢̢�                ����      �̢̢�            ��\n");
	printf("��                        ����                        ��\n");
	printf(" ����������������������������������������������������������������������������������������������������\n");
}

print_scissors() // ���� ���
{
	printf(" ����������������������������������������������\n");
	printf("��                        ��\n");
	printf("��          �̢�          ��\n");
	printf("��       �̢�             ��\n");
	printf("��    �̢�                ��\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ��\n");
	printf("���̢̢̢̢̢�            ��\n");
	printf("���̢̢̢̢̢̢�          ��\n");
	printf("���̢̢̢̢̢̢�          ��\n");
	printf("���̢̢̢̢̢�            ��\n");
	printf("���̢̢̢̢�              ��\n");
	printf("�� �̢̢�                 ��\n");
	printf("��                        ��\n");
	printf(" ����������������������������������������������\n");
}

print_rock() // ���� ���
{
	printf(" ����������������������������������������������\n");
	printf("��                        ��\n");
	printf("��         �̢̢̢�       ��\n");
	printf("��     �̢̢̢̢̢̢̢�   ��\n");
	printf("��   �̢̢̢̢̢̢̢̢̢� ��\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ��\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ��\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ��\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ��\n");
	printf("��  �̢̢̢̢̢̢̢̢̢�  ��\n");
	printf("��   �̢̢̢̢̢̢̢̢�   ��\n");
	printf("��     �̢̢̢̢̢̢�     ��\n");
	printf("��                        ��\n");
	printf(" ����������������������������������������������\n");
}

print_paper() // ���ڱ� ���
{
	printf(" ����������������������������������������������\n");
	printf("��                        ��\n");
	printf("��      �̢̢̢̢�        ��\n");
	printf("��    �̢̢̢�            ��\n");
	printf("��  �̢̢̢̢̢̢̢̢̢�  ��\n");
	printf("�� �̢̢̢̢̢̢�         ��\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ��\n");
	printf("�� �̢̢̢̢̢̢�         ��\n");
	printf("�� �̢̢̢̢̢̢̢̢̢̢� ��\n");
	printf("��  �̢̢̢̢̢�          ��\n");
	printf("��   �̢̢̢̢̢̢̢�     ��\n");
	printf("��     �̢̢�             ��\n");
	printf("��                        ��\n");
	printf(" ����������������������������������������������\n");
}

void generate_two_numbers(int *n1, int *n2) // ��ǻ�Ͱ� 1,2,3 �߿��� �����ϰ� 2���� ���� �ٸ� ���ڸ� ���� �ϱ�
{
	*n1 = rand() % 3 + 1;
	*n2 = rand() % 3 + 1;
		while(*n2 == *n1)
		{
			*n2 = rand() % 3 + 1;
		}
}

void show_record(int win, int lose) // ������ �����ִ� �Լ�
{
	if (win == 0 && lose == 0) // ��,�� �Ѵ� 0�� ��
	{
		system("cls");
		draw_line();
		printf("\n");
		printf("                �¸�:  0\n");
		printf("\n");
		printf("                �й�:  0\n");
		printf("\n");
		printf("                �·�:  0.00%% \n");
		printf("\n");
		draw_line();
		printf("\n");
		printf("�޴��� ���ư����� ����Ű�� �Է��ϼ���...\n");
		printf("\n");
	}
	else
	{
		system("cls");
		draw_line();
		printf("\n");
		printf("                �¸�:  %d\n", win);
		printf("\n");
		printf("                �й�:  %d\n", lose);
		printf("\n");
		printf("                �·�:  %.2f%% \n", win * 100.00 / (win + lose)); // �·� ����ε� ���� ��Ʈ���� ������ �Ҽ��� ����ϱ� ���� 100.00�̶� ��
		printf("\n");
		draw_line();
		printf("\n");
		printf("�޴��� ���ư����� ����Ű�� �Է��ϼ���...\n");
		printf("\n");
	}
	system("pause");
}

int win_lose_draw(int player_num, int com_num)  // ���� ���� ���� ���и� �����ϴ� �Լ�, �¸� 1, �й� -1, ��� 0 ����
{


	if (player_num == 1 && com_num == 3) //�� ���� ��ǻ�� �� (��)
	{
		return 1;
	}
	if (player_num == 2 && com_num == 1) //�� ���� ��ǻ�� ���� (��)
	{
		return 1;
	}
	if (player_num == 3 && com_num == 2) //�� �� ��ǻ�� ���� (��)
	{
		return 1;
	}
	if (player_num == 1 && com_num == 2) //�� ���� ��ǻ�� ���� (��)
	{
		return -1;
	}
	if (player_num == 2 && com_num == 3) //�� ���� ��ǻ�� �� (��)
	{
		return -1;
	}
	if (player_num == 3 && com_num == 1) //�� �� ��ǻ�� ���� (��)
	{
		return -1;
	}
	if (player_num == com_num) // ����� ��
	{
		return 0;
	}
}

void print_RPS(int play1, int play2)   // ���õ� ���� 2���� ���� ���� ���� �� �߿��� 2���� �� ���� ���
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

void print_select(int play1, int play2) // �� 2���� ���ڸ� ���� �� ������� ��� 
{
	if (play1 == 1 && play2 == 2)
		printf("����<2>, ����<1> >>\n");
	else if (play1 == 1 && play2 == 3)
		printf("����<1>, ��<3> >>\n");
	else if (play1 == 2 && play2 == 1)
		printf("����<2>, ����<1> >>\n");
	else if (play1 == 2 && play2 == 3)
		printf("��<3>, ����<2> >>\n");
	else if (play1 == 3 && play2 == 1)
		printf("����<1>, ��<3> >>\n");
	else if (play1 == 3 && play2 == 2)
		printf("��<3>, ����<2> >>\n");
}

void num_select(int *play1, int *play2) // �÷��̾ �Է��� 2���� ���ڸ� play1�̶� play2�� �ϳ��� �����Ѵ�. �׸��� 1,2,3 �߿��� ���� �ٸ� 2���� ���ڸ� �̵��� �Ѵ�.
{
	while (1)
	{
		scanf(" %d %d", play1, play2);
		if (*play1 != *play2 && *play1 <=3 && *play1 >=1 && *play2 <= 3 && *play2 >= 1)
		{
			break;
		}
		printf("����<1>, ����<2>, ��<3> >> ");
	}
}

int com_select(int n1, int n2, int play1, int play2) // n1�� n2�� ��ǻ�ͼ��� play1�� play2�� �� �����̴�. �÷��̾�� ��ǻ�Ͱ� ���� ���� 2���� ���� �� ��ǻ�Ͱ� �̱�� ���� �ϳ� ���� �� �ϵ��� �ϴ� �Լ�
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

int what_win(int player_final) // ���� ���� �� �߿��� �������� �̰���Ŀ� ���� ���� ���� �ٸ��� �ؼ� �̵��ϴ� ĭ ���� �����Ѵ�.
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

int game_quit_yes() //������ ���� �����ϴ� ��쿡 ���� �Լ�, Y Ȥ�� y�� ������ 1����, N Ȥ�� n�� ������ 0 ����
{
	char yesno; 

	printf("�̹� ������ �����Ͻðڽ��ϱ�?(y/n)");
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