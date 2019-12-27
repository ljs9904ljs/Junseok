#include<stdio.h>
#include<math.h> // 수학 계산을 위해 포함시킨다

int main()
{
	float n1,n2,n3,n4,n5,n6; // 입력할 숫자 6개가 저장될 실수형 변수 6개를 지정한다
	printf("Enter 6 numbers> "); // 수 6개를 입력하라고 말한다
	scanf("%f %f %f %f %f %f", &n1, &n2, &n3, &n4, &n5, &n6); // 실수형의 수 6개를 입력한다

	float sum; // 6개의 실수의 합을 저장할 변수 
	sum = n1 + n2 + n3 + n4 + n5 + n6; // 입력된 6개의 실수의 합을 구해서 sum에 저장한다
	printf("Sum: %.2f\n", sum); // 계산된 합계를 출력한다

	float b; // 평균값을 저장할 변수
	b = sum / 6; // 이 경우에서 평균은 sum을 6으로 나눈 것이므로 sum / 6을 한다
	printf("Average: %.2f\n", b); // 계산된 평균을 출력한다

	float c; // 편차의 제곱의 합을 구해서 저장할 변수
	c = pow(n1 - b, 2) + pow(n2 - b, 2) + pow(n3 - b, 2) + pow(n4 - b, 2) + pow(n5 - b, 2) + pow(n6 - b, 2); // 편차의 제곱의 합을 구하는 과정이다 pow를 이용한다

	float var; // 분산을 저장할 변수
	var = c / 6; // 이 경우에서 분산은 편차의 제곱의 합을 6으로 나눈 것이므로 c / 6을 한다
	printf("Variance: %.2f\n", var); // 계산된 분산을 출력한다

	float stdDev; // 표준 편차를 저장할 변수
	stdDev = sqrt(var); // 편차는 분산에 루트를 씌운 것이므로 sqrt를 이용해서 var에 대해 루트를 씌운다
	printf("Standard deviation: %.2f\n", stdDev); // 계산된 표준 편차를 출력한다
	return 0;
}
