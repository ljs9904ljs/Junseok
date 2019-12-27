/*
명예서약(Honor code)

“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”
무은재 학부 20180551 이준석
*/


#include <iostream>
#include <cstdio>

int height[1000000]; // 막대기 높이

int main() {
	int totStick; // 총 막대기 
	int leftSee = 1; //왼쪽에서 보았을 때 막대의 개수
	int rightSee = 1; //오른쪽에서 보았을 때 막대의 개수
	int seeSum; // 보이는 막대기 갯수의 합
	int i=0;
	int temp;

	std::scanf("%d", &totStick); // 총 갯수 입력
	
	do {  // https://kldp.org/node/110745   를 참조하여 숫자를 엔터키 누를 때까지 한 번에 넣는 방법을 알아냄
		std::scanf("%d", &height[i]);
		i++;
	} while (getc(stdin) == ' ');

	temp = height[0];
	for (i = 0; i < totStick; i++) {         //배열의 왼쪽에서부터 leftSee를 찾는다. 
		if (temp < height[i + 1]) {
			temp = height[i + 1];
			leftSee++;
		}	
	}
	temp = height[totStick - 1];
	for (i = (totStick - 1); i > (-1); i--) {  //배열의 오른쪽에서부터 rightSee를 찾는다. 
		if (temp < height[i - 1]) {
			temp = height[i - 1];
			rightSee++;
		}
	}

	seeSum = leftSee + rightSee;

	std::printf("%d", seeSum); // 보이는 막대기 개수 합 출력




	return 0;
}
