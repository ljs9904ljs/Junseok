#include <iostream>
#include <stdlib.h>
/* BEGIN_YOUR_CODE 
#include <WHATEVERYOUWANT>
 END_YOUR_CODE */
#include<cstdio>
int TAFunction(int argc);

using namespace std;

/* BEGIN_YOUR_CODE */

typedef struct node{
	int a; 
	struct node *next;
}NODE;

typedef struct list{
	NODE* head;
	int size;
}LIST;

void addNode(LIST* list, int* totNode) //���ο� node�� add
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	(*totNode)++;
	newNode->a = *totNode;
	NODE* cur;

	if (*totNode == 1) {
		newNode->next = newNode;
		list->head = newNode;
	}
	else {
		cur = list->head;
		while (cur) {
			if (cur->next == list->head) {
				cur->next = newNode;
				newNode->next = list->head;
				break;
			}
			cur = cur->next;
		}

	}
}

void delNode(LIST* list, int n) //list�ȿ� ����Ǿ��ִ� ��� node���� delete
{
	int i;
	NODE *temp, *cur;
	temp = list->head;
	for (i = 0; i<n ; i++) {
		cur = temp->next;
		free(temp);
		temp = cur;
	}
	return;

}

/* END_YOUR_CODE */

int Solve(int N, int K)
{
	int result = 0;
	
	/* BEGIN_YOUR_CODE */
	LIST* list = (LIST*)malloc(sizeof(LIST)); //list ����
	list->head = NULL; //list �ʱ�ȭ
	list->size = 0;  //list �ʱ�ȭ

	NODE *cur; // node�� ����Ų��.
	int totNode = 0; // �� node�� ����
	int i;
	int kill = 0; // ���� ������ ���� ���� count�Ѵ�.
	
	for (i = 0; i < N; i++) { //��� ����ŭ node�� �����Ѵ�.
		addNode(list, &totNode);
	}


	cur = list->head;

	while (kill != (N-1)) { // ���̴� ����( ���� ����� node ���� ���� a�� ���� -1�� �ٲ۴�. )
		if (kill == 0) { //�� ó���� ���� ��
			for (i = 0; i < K - 1; i++) {
				if (cur->a == -1) {
					cur = cur->next;
				}
				cur = cur->next;
			}
			cur->a = -1; // �׾����� �ǹ��Ѵ�.		
			kill++; // �� �� �׿����Ƿ� kill�� ���� �ϳ� ������Ų��.
			
		}
		else {
			for (i = 0; i < K; i++) {
				cur = cur->next;
				while (cur->a == -1) { //�̹� �׾��ִ� ����� �ǳ� �ٴ� ����
					cur = cur->next;
				}
			}
			cur->a = -1;
			kill++;
			
		}
	}

	while (1) { //����ִ� ����� ã�� �����̴�. ã�Ƽ� ���� result�� �����Ѵ�.
		if (cur->a != -1) {
			result = cur->a;
			break;
		}
			cur = cur->next;
	}
	
	delNode(list, N); //�Ҵ��� �����Ѵ�.
	free(list); //�Ҵ��� �����Ѵ�.
	

	/* END_YOUR_CODE */

	return result;   // safe position
}

int main(int argc, char** argv)
{
	int N = 0, K = 0;
	int result = 0;

	if (TAFunction(argc)) {
		N = atoi(argv[1]);
		K = atoi(argv[2]);
		cout << Solve(N, K);
		return 0;
	}

	/* BEGIN_YOUR_CODE */
	int a = 0, b = 0;
	cout << "N:";
	cin >> N;
	cout << "K:";
	cin >> K;

	result = Solve(N, K);
	cout << "result:" << result << endl;
	/* END_YOUR_CODE */
	
	return 0;
}

int TAFunction(int argc)
{
	if (argc > 2)
		return true;
	else
		return false;
}