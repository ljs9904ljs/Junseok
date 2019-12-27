#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
#define MAX_CACHE 1000

int cache[MAX_CACHE][MAX_CACHE];

/* BEGIN_YOUR_CODE */
int LCS(string& str1, string& str2) 
{ 
	int len1 = str1.length();  //length of str1 
	int len2 = str2.length();  //length of str2 
	int i, j;

	//첫번째 스트링의 i번째 글자와 두번째 스트링의 j번째(j를 1씩 증가시킨다 j의 끝까지 갔을 때 i를 1만큼 증가시킨다)를
	//비교해서 같으면, 최장 공통 수열 길이의 count를 증가시킨다.
	for (i = 0; i <= len1; i++)
	{
		for (j = 0; j <= len2; j++)
		{
			if (i == 0 || j == 0)
				cache[i][j] = 0;

			else if (str1[i - 1] == str2[j - 1])
				cache[i][j] = cache[i - 1][j - 1] + 1;

			else
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
		}
	}

	return cache[len1][len2];
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

/* END_YOUR_CODE */

int main()
{
	string str1, str2;

	cout << "Enter first string   ";
	getline(cin, str1);

	cout << "Enter second string   ";
	getline(cin, str2);

	int len1 = str1.length();  //length of str1 
	int len2 = str2.length();  //length of str2 

	printf("Length of longest common subsequence is %d \n", LCS(str1, str2));

	return 0;
}