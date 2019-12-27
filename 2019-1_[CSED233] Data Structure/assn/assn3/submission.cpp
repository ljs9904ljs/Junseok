#include<iostream>
#include<string>
using namespace std;


/* BEGIN_YOUR_CODE */

typedef struct node {
	struct node* next;
	char oneLetter;
}NODE;

typedef struct stack {
	NODE* top;
	int count;
}STACK;

int isEmpty(STACK* s) { // 비어있으면 1, 아니면 0 리턴
	return s->top == NULL;
}

int push(STACK* s, char oneLetter) { // 스택에 node를 추가한다. 성공하면 1, 실패하면 0 리턴
	NODE* temp;
	int success = 1;

	temp = (NODE*)malloc(sizeof(NODE));

	if (!temp)
		success = 0;
	else {
		temp->oneLetter = oneLetter;
		temp->next = s->top;
		s->top = temp;
		s->count++;
	}
	return success;
}

int pop(STACK* s, char* oneLetter) { // 스택에서 node를 제거한다. 성공하면 1, 실패하면 0 리턴
	NODE* temp;
	int success = 1;

	if (!isEmpty(s)) {
		*oneLetter = s->top->oneLetter;

		temp = s->top;
		s->count--;
		s->top = temp->next;

		free(temp);
	}
	else
		success = 0;

	return success;
}

bool MatchingParentheses(string ari_exp) { // 괄호들의 matching이 올바르게 이루어져 있는가? ( true or false ) 다음 세 조건을 이용한다. [1] 왼쪽 괄호 개수와 오른쪽 괄호 개수가 같아야 한다. [2] 오른쪽 괄호가 왼쪽 괄호보다 먼저 등장하면 안 된다. [3] 오른쪽 괄호 앞에 그에 맞는 왼쪽 괄호가 있어야 한다.
	int strLen; //문자열의 길이를 저장한다
	string a(ari_exp);
	strLen = a.length();
	char check; //pop에서 튀어나온 문자를 임시로 저장해둘 변수
	int i, t1, t2, t3;
	STACK* stack = (STACK*)malloc(sizeof(STACK)); //stack 활용
	stack->count = 0;
	stack->top = NULL;
	int count[6]; // 왼쪽 괄호와 오른쪽 괄호의 개수가 종류 별로 일치해야 한다. 그걸 위해 각각의 갯수를 저장해둘 배열이다.

	for (i = 0; i < strLen; i++) { // 괄호 종류 별 개수 저장
		if (ari_exp[i] == '(')
			count[0]++;
		else if (ari_exp[i] == '{')
			count[1]++;
		else if (ari_exp[i] == '[')
			count[2]++;
		else if (ari_exp[i] == ')')
			count[3]++;
		else if (ari_exp[i] == '}')
			count[4]++;
		else if (ari_exp[i] == ']')
			count[5]++;
	}

	for (i = 0; i < 3; i++) { // 왼쪽 괄호와 오른쪽 괄호 각각의 개수가 일치하는지 확인한다.
		if (count[i] != count[i + 3])
			return false;
	}

	for (i = 0; i < strLen; i++) {
		if (ari_exp[i] == ')' || ari_exp[i] == '}' || ari_exp[i] == ']') { //오른쪽 괄호를 만난다면
			if (ari_exp[i] == ')') { // 오른쪽 괄호가 나오면 그에 맞는 왼쪽 괄호가 나와야한다. 그에 대한 if - else if문
				t1 = pop(stack, &check);
				if (t1 == 0) //pop을 실패했다는 것은 오른쪽 괄호가 왼쪽 괄호보다 먼저 나왔다는 것이므로 matching이 올바르게 이루어져 있지 않다는 것을 의미한다.
					return false;
				if (check != '(')
					return false;
			}
			else if (ari_exp[i] == '}') {
				t2 = pop(stack, &check);
				if(t2 == 0) //pop을 실패했다는 것은 오른쪽 괄호가 왼쪽 괄호보다 먼저 나왔다는 것이므로 matching이 올바르게 이루어져 있지 않다는 것을 의미한다.
					return false;
				if (check != '{')
					return false;
			}
			else if (ari_exp[i] == ']') {
				t3 = pop(stack, &check);
				if(t3 == 0) //pop을 실패했다는 것은 오른쪽 괄호가 왼쪽 괄호보다 먼저 나왔다는 것이므로 matching이 올바르게 이루어져 있지 않다는 것을 의미한다.
					return false;
				if (check != '[')
					return false;
			}
		}
		else { // 왼쪽 괄호들은 stack에 push 해둔다.
			push(stack, ari_exp[i]);
		}
	}
	free(stack); //동적할당 메모리 해제
	return true;
}
/* END_YOUR_CODE */


int main()
{
	string ari_exp;
	cout << "Enter an arithmetic expression:  ";
	cin >> ari_exp;
	if (MatchingParentheses(ari_exp))
		cout << "Correct\n";
	else
		cout << "Incorrect\n";
}