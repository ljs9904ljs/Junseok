/*
명예서약(Honor code)

“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”

무은재학부 20180551 이준석
*/
// https://jun-itworld.tistory.com/21 를 참조하였다.

#include <cstdio>

using namespace std;

int height[1000][1000]; // 빙하의 지도
int afterYear[1000][1000]; // y년이 지난 후 빙하가 녹았는지 안 녹았는지를 기록할 배열
int alpha[4] = { 1, -1, 0, 0 }; // dfs에서 상하좌우만 탐색하고 대각선은 탐색하지 않도록 하기 위한 방법이다.
int beta[4] = { 0, 0, -1, 1 };  // dfs에서 상하좌우만 탐색하고 대각선은 탐색하지 않도록 하기 위한 방법이다.


void dfs(int x, int y, int W, int H) {
	int a, b, i, j;

	if (afterYear[x][y] == 1) { // dfs를 진행하면서 이어진 빙하가 중복되게 count되지 않도록 해준다.
		afterYear[x][y] = 0;
	}
	else {
		return;
	}

	if (x < 0 || y < 0 || y >= W || x >= H) //상하좌우 탐색 시에 arr[-1][0]과 같이 존재하지 않는 배열을 탐색하지 않도록 해준다.
		return;

	for (i = 0; i < 4; i++) {
			a = x + alpha[i]; // dfs에서 상하좌우만 탐색하고 대각선은 탐색하지 않도록 하기 위한 방법이다.
			b = y + beta[i]; // dfs에서 상하좌우만 탐색하고 대각선은 탐색하지 않도록 하기 위한 방법이다.

			dfs(a, b, W, H);
	}

	//if ()
}

int makeMap(int W, int H) {
	int i, j;
	int maxHeight = 0; //가장 높은 빙하의 높이

	for (i = 0; i < H; i++) { //수를 입력받아 빙하의 지도를 만든다. 동시에 가장 높은 빙하의 높이도 구한다.
		for (j = 0; j < W; j++) {
			scanf("%d", &height[i][j]);
			maxHeight < height[i][j] ? maxHeight = height[i][j] : maxHeight;
		}
	}
	return maxHeight; // 가장 높은 빙하의 높이를 return한다.
}

void melt(int W, int H, int year) { // 임의의 배열을 추가로 또 만들어서 y년이 지난 후에 얼음이 남아 있는지 아닌지 기록한다.
	int i, j;
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (height[i][j] <= year) {
				afterYear[i][j] = 0; //녹음
			}
			else {
				afterYear[i][j] = 1; //안 녹음
			}
		}
	}
}

int iceCount(int W, int H) {
	int i, j;
	int notMelt = 0; //녹지 않은 빙하의 수를 센다. 상하좌우로 이어져 있는 것은 하나로 본다.

	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (afterYear[i][j] == 1) {
				dfs(i, j, W, H); // 빙하 전체를 탐색한다. 배열의 특정 위치에 대해 상하좌우를 탐색해서 이어져 있는 빙하가 중복되게 count되지 않도록 한다.
				notMelt++;
			}
		}
	}

	return notMelt; // 녹지 않은 빙하가 몇 덩어리인지를 return 한다.
}

int main() {

	int W, H, y; //W는 가로 길이, H는 세로 길이, y는 몇 년이 지난 뒤인지를 뜻한다.
	int i, j, temp;
	int mxh; // 최대 높이
	int result = 0; // 남아 있는 빙하의 덩어리 수

	scanf("%d %d %d", &W, &H, &y); //W,H,y의 값을 입력 받는다.
	mxh = makeMap(W, H); // 빙하 지도를 만든다. 가장 높은 빙하의 높이가 return 된다.

	melt(W, H, y); // y년이 흐른 후 녹은 것과 안 녹은 것 기록

	result = iceCount(W, H); // 남아 있는 빙하 덩어리 수 기록
		
	printf("%d", result);

	return 0;
}
