#include<stdio.h>

int getStu(FILE* infile, int* ID, int* mid, int* final);
void calcGrade(int mid, int final, float* total, char* grade);
void writeGrade(FILE* outfile, int ID, float total, char grade);


int main()
{
	FILE *infile;
	FILE *outfile;

	int ID, mid, final;
	float total;
	float score_total = 0;
	char grade;
	int student = 0;

	int result;
	infile = fopen("score.txt", "r");

	if (infile == NULL)
	{
		printf("cannot open score.txt file\n");
		return 100;
	}

	outfile = fopen("report.txt", "w");
	if (outfile == NULL)
	{
		printf("cannot open report.txt file\n");
		return 101;
	}

	fprintf(outfile, "=========================\n");
	fprintf(outfile, "  ÇÐ¹ø     ÃÑÁ¡(ÇÐÁ¡)\n");
	fprintf(outfile, "=========================\n");


	while (getStu(infile, &ID, &mid, &final))   
	{
		calcGrade(mid, final, &total, &grade);
		writeGrade(outfile, ID, total, grade);
		score_total = score_total + total;
		student++;
	}
	fprintf(outfile, "=========================\n");
	fprintf(outfile, "  Æò±Õ     %.1f\n", score_total / student);  
	fprintf(outfile, "=========================\n");

	fclose(outfile);
	fclose(infile);

	printf("End");
	return 0;
}

int getStu(FILE* infile, int* ID, int* mid, int* final)
{
	int result;
	result = fscanf(infile, "%d%d%d", ID, mid, final);
	if (result == EOF)
		return 0;
	else
		return 1;
}

void calcGrade(int mid, int final, float* total, char* grade)
{
	*total = (float)mid * 0.4 + (float) final * 0.6;

	if (*total >= 90)
		*grade = 'A';
	else if (*total >= 80)
		*grade = 'B';
	else if (*total >= 70)
		*grade = 'C';
	else if (*total >= 60)
		*grade = 'D';
	else
		*grade = 'F';

}

void writeGrade(FILE* outfile, int ID, float total, char grade)
{
	fprintf(outfile, "  %6d      %.1f (%c)\n", ID, total, grade);
}