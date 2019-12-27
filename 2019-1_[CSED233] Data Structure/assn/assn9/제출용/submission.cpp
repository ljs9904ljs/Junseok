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
	int i, j, k;
	int idx1, idx2;
	idx1 = mid - left + 1;
	idx2 = right - mid;

	//�ӽ� �迭 ���� �Ҵ�
	int* leftSide = new int[idx1];
	int* rightSide = new int[idx2];

	//�ӽ� �迭�� ���� �����Ѵ�.
	for (i = 0; i < idx1; i++) {
		leftSide[i] = input[left + i];
	}
	for (i = 0; i < idx2; i++) {
		rightSide[i] = input[mid + 1 + i];
	}

	i = 0;
	j = 0;
	k = left;

	//�ӽ� �迭�κ��� ���� �ҷ����� �����ϸ鼭 �����Ѵ�.
	while (i < idx1 && j < idx2) {
		if (leftSide[i] <= rightSide[j]) {
			input[k] = leftSide[i];
			i++;
		}
		else {
			input[k] = rightSide[j];
			j++;
		}
		k++;
	}
	
	//�ӽ� �迭���� ���� �ִ� �κе��� �ٽ� ������ �迭�� �ű��.
	while (i < idx1) {
		input[k] = leftSide[i];
		i++;
		k++;
	}
	while (j < idx2) {
		input[k] = rightSide[j];
		j++;
		k++;
	}

	delete[] leftSide;
	delete[] rightSide;

	return;
}

/* You can modify your function as long as the input is one dimensional integer array */
void merge_sort(int input[], int left, int right)
{
	if (left < right) {
		int middle;
		middle = (left + right) / 2;
		merge_sort(input, left, middle);
		merge_sort(input, middle + 1, right);
		merge(input, left, middle, right);
	}
	// .....
	//merge(input, .....)
	//merge_sort(input, ......)
	// .....
	return;
}

void mySwap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int input[], int start, int end)
{
	int pivot, temp, low, high;

	low = start;
	high = end + 1;
	pivot = input[start];

	do {
		do {
			low++;
		} while (low <= end && input[low] < pivot);

		do {
			high--;
		} while (high >= start && input[high] > pivot);

		if (low < high) {
			mySwap(&input[low], &input[high]);
		}

	} while (low < high);

	mySwap(&input[start], &input[high]);

	return high;


}


/* You can modify your function as long as the input is one dimensional integer array */
void quick_sort(int input[], int start, int end)
{
	int pivot;
	//quick_sort(input, ....)
	if (start < end) {
		pivot = partition(input, start, end);

		quick_sort(input, start, pivot - 1);
		quick_sort(input, pivot + 1, end);


	}



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
	merge_sort(list, 0, n-1);
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
	quick_sort(list, 0, n - 1);
	
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