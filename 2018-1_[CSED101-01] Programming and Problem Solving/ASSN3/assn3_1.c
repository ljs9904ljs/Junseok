#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_PLAYER 10


void GenerateLadder(int num_player, int num_hline, int ladder[][2]);
int SaveLadder(int num_player, int num_hline, int ladder[][2]);

int main()
{
	int people; //���� �ο� ��
	int garo;   //�������� ����
	int ladder[(MAX_PLAYER - 1) * 5][2]; //��ٸ��� ������ 2���� �迭, ������ ������ 1 ������ 0 ����

	srand(time(NULL));
	
		printf("�����ο���: "); 
		scanf("%d", &people); //�����ο����� �Է¹޴´�.
		printf("������ ����: ");
		scanf("%d", &garo);// �������� ������ �Է¹޴´�.

		if (people < 2 || people >10) //���⼭���� ���ǹ��� ������ �����ο����� �������� ������ ������ �´� �Է¸��� �������Ѵ�. ���ǿ� ���� ������ ���α׷��� �����Ѵ�.
		{
			printf("�Է��� �߸��ƽ��ϴ�.\n");
			return 0;
		}
		else if (2 <= people && people <= 4)
		{
			if (garo < 0 || garo >10)
			{
				printf("�Է��� �߸��ƽ��ϴ�.\n");
				return 0;
			}
		}
		else if (5 <= people && people <= 7)
		{
			if (garo < 0 || garo > 20)
			{
				printf("�Է��� �߸��ƽ��ϴ�.\n");
				return 0;
			}
		}
		else if (8 <= people && people <= 10)
		{
			if (garo < 0 || garo > 30)
			{
				printf("�Է��� �߸��ƽ��ϴ�.\n");
				return 0;
			}
		}
		
			ladder[0][0] = people; //�迭�� 1�� 1���� ������ ���� �����Ѵ�
			ladder[0][1] = garo;   //�迭�� 1�� 2���� �������� ������ �����Ѵ�
			GenerateLadder(people, garo, ladder); // ��ٸ��� �����Ѵ�.
			SaveLadder(people, garo, ladder); // ��ٸ��� �ؽ�Ʈ ���Ͽ� �����Ѵ�.
		

	return 0;
}

void GenerateLadder(int num_player, int num_hline, int ladder[][2]) // ��ٸ��� �����ϴ� �Լ�
{

	while (1) //�������� ��� ������ (2���� �迭�� �Է�)
	{
		int i, check = 1;
		for (i = 1;i <= num_hline;i++) // �迭�� 1���� 1~10 ������, ��ٸ��� ���� ��ȣ �����ϰ� ���� ( ��� ������ ����.)
		{
			ladder[i][0] = rand() % 10 + 1;
		}

		for (i = 1;i <= num_hline;i++) // �迭�� 2���� �������� ���� ��ġ�� �����ϰ� ���� ( ��� ������ �ִ�.)
		{
			ladder[i][1] = rand() % (num_player - 1) + 1;
		}
		//�迭�� 2���� ���� ������ ������Ű�� ���ؼ� while(1)�� ����, ���� ���� �� while���� break�ϱ� ���� �Ʒ� ���� ���
		int j;
		int k;
		for (j = 1;j <= num_hline;j++)
		{
			for (k = 1;k <= num_hline;k++)
			{
				if (ladder[j][0] == ladder[k][0])  //��ٸ��� ���� ��ȣ�� ���ٸ�
				{
					if (ladder[j][1] + 1 == ladder[k][1]) 
					{
						check = 0;
						break; // if ������ �����ϸ� break�Ѵ�.
					}
				}//�������� ���ٸ�
			}//k�� for��
			if (check == 0)
				break;
		}//j�� for��
		if (check == 1)
			break;
	}//while��
}

int SaveLadder(int num_player, int num_hline, int ladder[][2]) // ������� ��ٸ��� ���� �����͸� �ؽ�Ʈ ���Ϸ� �����س���.
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

