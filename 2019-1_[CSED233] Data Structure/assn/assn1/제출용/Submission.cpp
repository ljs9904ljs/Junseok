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

void addNode(LIST* list, int* totNode) //새로운 node를 add
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

void delNode(LIST* list, int n) //list안에 연결되어있는 모든 node들을 delete
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
	LIST* list = (LIST*)malloc(sizeof(LIST)); //list 생성
	list->head = NULL; //list 초기화
	list->size = 0;  //list 초기화

	NODE *cur; // node를 가리킨다.
	int totNode = 0; // 총 node의 개수
	int i;
	int kill = 0; // 죽일 때마다 죽인 수를 count한다.
	
	for (i = 0; i < N; i++) { //사람 수만큼 node를 생성한다.
		addNode(list, &totNode);
	}


	cur = list->head;

	while (kill != (N-1)) { // 죽이는 과정( 죽은 사람은 node 안의 변수 a의 값을 -1로 바꾼다. )
		if (kill == 0) { //맨 처음에 죽일 때
			for (i = 0; i < K - 1; i++) {
				if (cur->a == -1) {
					cur = cur->next;
				}
				cur = cur->next;
			}
			cur->a = -1; // 죽었음을 의미한다.		
			kill++; // 한 명 죽였으므로 kill의 수를 하나 증가시킨다.
			
		}
		else {
			for (i = 0; i < K; i++) {
				cur = cur->next;
				while (cur->a == -1) { //이미 죽어있는 사람을 건너 뛰는 과정
					cur = cur->next;
				}
			}
			cur->a = -1;
			kill++;
			
		}
	}

	while (1) { //살아있는 사람을 찾는 과정이다. 찾아서 변수 result에 대입한다.
		if (cur->a != -1) {
			result = cur->a;
			break;
		}
			cur = cur->next;
	}
	
	delNode(list, N); //할당을 해제한다.
	free(list); //할당을 해제한다.
	

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