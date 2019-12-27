/*
명예서약(Honor code)

“나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.”
무은재 학부 20180551 이준석
*/

//https://www.crocus.co.kr/583  를 참조하여 작성(LIS에 대한 내용)

#include <cstdio>
#include <algorithm>

using namespace std;
int lis[1000001]; //최장 증가 수열을 만들어서 저장할 배열이다.
int height[1000001]; //나무 막대기의 높이를 입력받아 저장해놓을 배열이다.

int lowerBound(int start, int end, int *arr, int target) //주어진 값보다 작거나 같은 값을 찾는 함수
{
	int mid;
	while (end - start > 0)  // 주어진 범위[start,end]에서 탐색하도록 한다. start == end이면 반복 종료
	{
		mid = (start + end) / 2;  // 주어진 범위의 중간 위치를 계산한다

		if (arr[mid] < target) // 찾고자 하는 값보다 작으면 오른쪽으로 한 칸만 더 시작 구간 갱신
			start = mid + 1;

		else  // 찾고자 하는 값보다 크면 거기까지 끝 구간 갱신
			end = mid;
	}
	return end + 1; // 찾는 구간에 없는 경우 가장 마지막 +1 위치 전달
}


int main()
{
	int i, n, j = 0;
	int cnt = 0;

	scanf("%d", &n); //나무 막대기의 개수 n을 입력한다.

	for (i = 0; i < n; i++){ //나무 막대기 n개의 높이들을 입력한다.
		scanf("%d", &height[i]);
	}
	i = 0;

	lis[i] = height[i];
	i++;

	while (i < n)
	{
		
		if (lis[j] < height[i]) { // lis의 가장 큰 값보다 더 큰값이 들어오면
			lis[j + 1] = height[i];
			j++;
		}

		else {
			int ans = lowerBound(0, j, lis, height[i]);
			lis[ans - 1] = height[i];
		}

		i++;
	}

	printf("%d", j + 1);

	return 0;
}
