/* 
 * �ۼ���:
 * ��  ��: xxxxxxxx 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING 20

// ���� ��� ����ü NODE ����
//---------- ����� ä��� ----------//

// ���� ��� ����ü STACK ����
//---------- ����� ä��� ----------//

void printStack(STACK *s);
int push(STACK *s, char data);
int pop(STACK *s, char *data);
int isEmpty(STACK *s);

int main()
{
	int len, i, ioRes;
	char str[MAX_STRING];
	STACK *stack;

	// ���� ��� ����(�����Ҵ�) �� �ʱ�ȭ
	//---------- ����� ä��� ----------//  ���� �Ҵ�
	if (!stack)
	{
		printf("���� �Ҵ� ����\n");
		return 100;
	}

	//---------- ����� ä��� ----------// �ʱ�ȭ



	while (1)
	{
		printf(">> ");
		ioRes = scanf("%s", str);

		if (ioRes == EOF)
			break;

		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			//---------- ����� ä��� ----------// push �Լ� ȣ��
		}
		printStack(stack);

	} // while

	free(stack);
	printf("bye!\n");

	return 0;
} // main

void printStack(STACK *s)
{
	char data;

	printf("   ");
	while (//---------- ����� ä��� ----------//) // ������ �� ������ pop �Լ� ȣ��
	{
		printf("%c", data);
	}
	printf("\n\n");

} // printStack

// push ������ 1, ���н� 0�� ��ȯ
int push(STACK *s, char data)
{
	NODE *temp;
	int success = 1;

	// ���� ��� ����
	temp = //---------- ����� ä��� ----------//;
	if (!temp) // ���� �Ҵ� ���н�
		success = 0;
	else
	{
		//---------- ����� ä��� ----------//





	}

	return success;
} // push

// pop ������ 1, ���н� 0�� ��ȯ
int pop(STACK *s, char *data)
{
	NODE *temp;
	int success = 1;

	if (//---------- ����� ä��� ----------//) // ������ ��� ���� ������(isEmpty �Լ� ȣ��)
	{
		*data = //---------- ����� ä��� ----------//;

		//---------- ����� ä��� ----------//




		free(//---------- ����� ä��� ----------//); // ��� ����
	}
	else
		success = 0;

	return success;
} // pop

// ������ ��� ������ 1, �׷��� ������ 0�� ��ȯ
int isEmpty(STACK *s)
{
	//---------- ����� ä��� ----------//
} // isEmpty
