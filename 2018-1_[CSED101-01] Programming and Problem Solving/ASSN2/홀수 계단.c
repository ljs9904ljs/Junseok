#include<stdio.h>


int main()
{

	printf("������ ���� ����� ������ �Է�(10~30) >> ");

	int stair;
	scanf(" %d", &stair);





	if (stair >= 10 && stair <= 30 && stair % 2 == 1)   // ��� ������ 10~30�̶�� �����Ѵ� �׸��� Ȧ���� ��
	{
		int a, b, c;


		for (a = 0; a < (stair / 2 + 1); a++)  // ��� ������ Ȧ�� �� ��
		{
			for (b = 0; b <= a; b++)
			{
				printf("��");
			}
			for (b = 0; b <= -3 + (stair - 1 - 2 * (a - 1)); b++)
			{
				printf("  ");
			}
			for (c = 0; c <= a; c++)
			{
				printf("��");
			}
			printf("\n");
		}

	}
	
	if (stair >= 10 && stair <= 30 && stair % 2 == 0) // ��� ������ 10~30�̶�� �����Ѵ� �׸��� ¦���� ��
	{
		int i, j, k;

		for (i = 0; i < (stair / 2); i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf("��");
			}
			for (j = 0; j <= (stair - 1 - 2 * (i - 1)); j++)
			{
				printf("  ");
			}
			for (k = 0; k <= i, k++)
			{
				printf("��");
			}
			printf("\n");
		}


	}

	return 0;
}

//���� �����̴� �Լ��� ������. ù ĭ�� �׳� �ϰ� �� ° ĭ�� \n�ϰ� �����̽��� �� �� ������ ������ ����.
