#include<stdio.h>

float calc_average(int score1, int score2);
char calc_grade(float average);

int main()
{
	int score1, score2;
	float average;

	printf("enter your midterm score :");
	scanf("%d", &score1);
	printf("\nenter your final score :");
	scanf("%d", &score2);

	average = calc_average(score1, score2);

	printf("average :%.1f\n", calc_average(score1, score2));
	printf("grade :%c\n", calc_grade(average));

	return 0;
}


float calc_average(int score1, int score2)
{
	return((score1 + score2) / 2);
}

char calc_grade(float average)
{
	if (average >= 90)
	{
		return 'A';
	}
	else if (average >= 80)
	{
		return 'B';
	}
	else if (average >= 70)
	{
		return 'C';
	}
	else if (average >= 60)
	{
		return 'D';
	}
	else
	{
		return 'E';
	}
}