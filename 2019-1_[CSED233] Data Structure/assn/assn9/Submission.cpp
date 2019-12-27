#include <iostream>
#include <time.h>
/* BEGIN_YOUR_CODE
#include <WHATEVERYOUWANT>
 END_YOUR_CODE */

using namespace std;

/* BEGIN_YOUR_CODE */

/* You can modify your function as long as the input is one dimensional integer array */
void merge(int input[], int left, int mid, int right)
{
	return;
}

/* You can modify your function as long as the input is one dimensional integer array */
void merge_sort(int input[], int left, int right)
{
	// .....
	//merge(input, .....)
	//merge_sort(input, ......)
	// .....
	return;
}

/* You can modify your function as long as the input is one dimensional integer array */
void quick_sort(int input[], int start, int end)
{
	//quick_sort(input, ....)
	return;
}

/* END_YOUR_CODE */


#define INPUT_MAX 99999
int main(int argc, char** argv)
{
	int n = 0;
	float gap_merge = 0.0, gap_quick = 0.0;
	time_t startTime, endTime;

	int input[INPUT_MAX] = { 0, };
	int list[INPUT_MAX] = { 0, };

	/* BEGIN_YOUR_CODE */
	cout << "size of input: ";
	cin >> n;

	cout << "Input data >> ";
	for (int i = 0; i < n; ++i)
		cin >> input[i];

	cout << "INPUT >> ";
	for (int i = 0; i < n; ++i)
		cout << input[i] << " ";
	cout << "\n\n";
	/* END_YOUR_CODE */

	memcpy(list, input, sizeof(int)*n);
	startTime = clock();
	/* BEGIN_YOUR_CODE */
	//merge_sort(list, .....);
	/* END_YOUR_CODE */
	endTime = clock();
	gap_merge = (float)(endTime - startTime) / (CLOCKS_PER_SEC);

	cout << "merge_sort(): " << endl;
	for (int i = 0; i < n; ++i)
		cout << list[i] << " ";
	cout << "\n\n";

	memcpy(list, input, sizeof(int)*n);
	startTime = clock();
	/* BEGIN_YOUR_CODE */
	//quick_sort(list, ......)
	/* END_YOUR_CODE */
	endTime = clock();
	gap_merge = (float)(endTime - startTime) / (CLOCKS_PER_SEC);

	cout << "quick_sort(): " << endl;
	for (int i = 0; i < n; ++i)
		cout << list[i] << " ";
	cout << "\n\n";

	cout << "merge: " << gap_merge << " secs" << endl;
	cout << "quick: " << gap_quick << " secs" << endl;

	return 0;
}