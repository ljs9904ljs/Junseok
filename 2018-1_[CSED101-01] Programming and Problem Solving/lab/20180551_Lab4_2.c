#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int season_print(int month);


int main()
{
	int month1, month2, month3;
	srand(time(NULL));
	month1 = rand() % 12 + 1;
	month2 = rand() % 12 + 1;
	month3 = rand() % 12 + 1;

	season_print(month1);
	season_print(month2);
	season_print(month3);


	return 0;
}

int season_print(int month)
{
	if (month == 3 || month == 4 || month == 5)
	{
		printf("%d��, ��\n", month);
	}
	else if (month == 6 || month == 7 || month == 8)
	{
		printf("%d��, ����\n", month);
	}
	else if (month == 9 || month == 10 || month == 11)
	{
		printf("%d��, ����\n", month);
	}
	else if (month == 12 || month == 1 || month == 2)
	{
		printf("%d��, �ܿ�\n", month);
	}
}