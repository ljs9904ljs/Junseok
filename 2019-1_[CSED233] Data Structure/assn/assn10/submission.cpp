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

	//ù��° ��Ʈ���� i��° ���ڿ� �ι�° ��Ʈ���� j��°(j�� 1�� ������Ų�� j�� ������ ���� �� i�� 1��ŭ ������Ų��)��
	//���ؼ� ������, ���� ���� ���� ������ count�� ������Ų��.
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