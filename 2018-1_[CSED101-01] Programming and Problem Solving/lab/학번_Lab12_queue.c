/* 
 * �ۼ���:
 * ��  ��: xxxxxxxx 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING 20

 // ť ��� ����ü NODE ����
typedef struct node
{
	char data;
	struct node *next;
} NODE;

// ť ��� ����ü QUEUE ����
typedef struct
{
	int count;
	NODE *front;
	NODE *rear;
} QUEUE;

void printQueue(QUEUE *q);
int enqueue(QUEUE *q, char data);
int dequeue(QUEUE *q, char *data);
int isEmpty(QUEUE *q);

int main()
{
	int len, i, ioRes;
	char str[MAX_STRING];
	QUEUE queue; // ť

	// ť �ʱ�ȭ
	//---------- ����� ä��� ----------//



	while (1)
	{
		printf(">> ");
		ioRes = scanf("%s", str);

		if (ioRes == EOF)
			break;

		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			//---------- ����� ä��� ----------// enqueue �Լ� ȣ��
		}

		printQueue(&queue);

	} // while

	printf("bye!\n");

	return 0;
} // main

void printQueue(QUEUE *q)
{
	char data;

	printf("   ");
	while (//---------- ����� ä��� ----------//) // ť�� �� ������ dequeue �Լ� ȣ��
	{
		printf("%c", data);
	}
	printf("\n\n");
} // printQueue

// enqueue ������ 1, ���н� 0
int enqueue(QUEUE *q, char data)
{
	NODE *temp;

	// ť ��� ����
	temp = //---------- ����� ä��� ----------//;
	if (!temp) // ���� �Ҵ� ���н�
		return 0;

	// ������ ��忡 �� ����
	//---------- ����� ä��� ----------//



	if (//---------- ����� ä��� ----------//) // ť�� ��� �ִ� ���(isEmpty �Լ� ȣ��)
	{
		//---------- ����� ä��� ----------//

	}
	else
	{
		//---------- ����� ä��� ----------//
	}

	q->count++;

	return 1;
} // enqueue

// dequeue ������ 1, ���н� 0
int dequeue(QUEUE *q, char *data)
{
	NODE *temp;

	if (isEmpty(q)) // ť�� ��� �ִ� ���
		return 0;

	*data = //---------- ����� ä��� ----------//;
	//---------- ����� ä��� ----------//




	return 1;
} // dequeue

// ť�� ��� ������ 1, �׷��� ������ 0�� ��ȯ
int isEmpty(QUEUE *q)
{
	//---------- ����� ä��� ----------//
}
