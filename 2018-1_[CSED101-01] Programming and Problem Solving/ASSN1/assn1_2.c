#include<stdio.h>
#include<math.h> // ���� ����� ���� ���Խ�Ų��

int main()
{
	float n1,n2,n3,n4,n5,n6; // �Է��� ���� 6���� ����� �Ǽ��� ���� 6���� �����Ѵ�
	printf("Enter 6 numbers> "); // �� 6���� �Է��϶�� ���Ѵ�
	scanf("%f %f %f %f %f %f", &n1, &n2, &n3, &n4, &n5, &n6); // �Ǽ����� �� 6���� �Է��Ѵ�

	float sum; // 6���� �Ǽ��� ���� ������ ���� 
	sum = n1 + n2 + n3 + n4 + n5 + n6; // �Էµ� 6���� �Ǽ��� ���� ���ؼ� sum�� �����Ѵ�
	printf("Sum: %.2f\n", sum); // ���� �հ踦 ����Ѵ�

	float b; // ��հ��� ������ ����
	b = sum / 6; // �� ��쿡�� ����� sum�� 6���� ���� ���̹Ƿ� sum / 6�� �Ѵ�
	printf("Average: %.2f\n", b); // ���� ����� ����Ѵ�

	float c; // ������ ������ ���� ���ؼ� ������ ����
	c = pow(n1 - b, 2) + pow(n2 - b, 2) + pow(n3 - b, 2) + pow(n4 - b, 2) + pow(n5 - b, 2) + pow(n6 - b, 2); // ������ ������ ���� ���ϴ� �����̴� pow�� �̿��Ѵ�

	float var; // �л��� ������ ����
	var = c / 6; // �� ��쿡�� �л��� ������ ������ ���� 6���� ���� ���̹Ƿ� c / 6�� �Ѵ�
	printf("Variance: %.2f\n", var); // ���� �л��� ����Ѵ�

	float stdDev; // ǥ�� ������ ������ ����
	stdDev = sqrt(var); // ������ �л꿡 ��Ʈ�� ���� ���̹Ƿ� sqrt�� �̿��ؼ� var�� ���� ��Ʈ�� �����
	printf("Standard deviation: %.2f\n", stdDev); // ���� ǥ�� ������ ����Ѵ�
	return 0;
}