#include<stdio.h>
#define PI 3.14

float areaSphere(float radius);
float volSphere(float radius);
void printResult(float area, float volume);

int main(void)
{
	float radius;
	float area, volume;

	printf("Enter the radius of the sphere: ");
	scanf("%f", &radius);

	area = areaSphere(radius);
	volume = volSphere(radius);

	printResult(area, volume);

	return 0;
}

float areaSphere(float radius)
{
	return (4 * PI*radius*radius);
}

float volSphere(float radius)
{
	return (PI*radius*radius*radius * 4 / 3.);
}

void printResult(float area, float volume)
{
	printf("Area : %.2f\n", area);
	printf("volume : %.2f\n", volume);
}