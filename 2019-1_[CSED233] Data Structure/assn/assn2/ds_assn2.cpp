#include<iostream>
#define MOD 100

using namespace std;


/* BEGIN_YOUR_CODE */
int f(int n) { //2 X N 배열을 채우는 경우의 수
	int result, prev = 3, prevPrev = 1;
	int i;

	if (n == 1)
		return 1;
	if (n == 2)
		return 3;

	for (i = 2; i < n; i++) {
		result = prev + 2 * prevPrev; //a[n]을 2xn을 채우는 경우의 수라고 했을 때, a[n] = a[n-1] + 2 * a[n-2] 이므로
		prevPrev = prev;
		prev = result;
	}

	return result;


}
/* END_YOUR_CODE */

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("[Error] You should input the width N\n");
		return 0;
	}

	int N = atoi(argv[1]);
	cout << f(N) //% MOD << endl;

	return 0;
}