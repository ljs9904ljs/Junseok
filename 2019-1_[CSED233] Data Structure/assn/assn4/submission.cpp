#include<time.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;


// Vector ADT based on the simple array-based implementation
class Vector {
private:
	/* BEGIN_YOUR_CODE */
	int arr[10000] = { 0, };
	int size = 0;
	int temp[10000];
	/* END_YOUR_CODE */

public:
	void insert_front(int x) {
		/* BEGIN_YOUR_CODE */
		int i;

		if (size == 0) {
			arr[0] = x;
			size++;
		}
		else if (size == 10000) {
			cout << "ERROR: over the size!" << endl;
			return;
		}
		else {
			for (i = 0; i < size; i++) {
				temp[i] = arr[i];
			}
			arr[0] = x;
			for (i = 0; i < size; i++) {
				arr[i + 1] = temp[i];
			}
			size++;
		}
		/* END_YOUR_CODE */
	}

	void delete_front() {
		/* BEGIN_YOUR_CODE */
		int i;
		
		if (size == 0) {
			cout << "ERROR: there is no data!" << endl;
			return;
		}
		else if (size == 1) {
			arr[0] = 0;
			size--;
		}
		else {
			for (i = 0; i < size; i++) {
				temp[i] = arr[i];
			}
			for (i = 0; i < size; i++) {
				arr[i] = temp[i];
			}
			size--;
		}
		/* END_YOUR_CODE */
	}

	void insert_back(int x) {
		/* BEGIN_YOUR_CODE */
		int i;

		if (size == 10000) {
			cout << "ERROR: over the size!" << endl;
			return;
		}
		else {
			arr[size] = x;			
			size++;
		}
		/* END_YOUR_CODE */
	}

	void delete_back() {
		/* BEGIN_YOUR_CODE */
		int i;

		if (size == 0) {
			cout << "ERROR: there is no data!" << endl;
			return;
		}
		else {
			arr[size-1] = 0;
			size--;
		}

		/* END_YOUR_CODE */
	}

	void print_content() {
		/* BEGIN_YOUR_CODE */
		int i;
		if (size == 0) {
			cout << "There is no array!!!" << endl;
			return;
		}
		for (i = 0; i < size; i++) {
			cout << arr[i] << "  ";
		}
		/* END_YOUR_CODE */
	}
};

// Vector ADT based on an Extenable Array used in a Circular fashion (EAC)
class EAC_vector {
private:
	/* BEGIN_YOUR_CODE */
	int size = 0;
	int arr[10000];
	int front = 0;
	int	back = 9999;
	/* END_YOUR_CODE */

public:
	void insert_front(int x) {
		/* BEGIN_YOUR_CODE */
		if (front == 0) {
			front = 9999;
			arr[front] = x;
			size++;
	
		}
		else {
			front--;
			arr[front] = x;
			size++;
	
		}
		
		/* END_YOUR_CODE */
	}

	void delete_front() {
		/* BEGIN_YOUR_CODE */
		if (size == 0) {
			cout << "EMPTY" << endl;
		}
		else {
			arr[front] = -1;
			front = (front + 1) % 10000;
			size--;
		
		}
	

		/* END_YOUR_CODE */
	}

	void insert_back(int x) {
		/* BEGIN_YOUR_CODE */
		
		if (back == 9999) {
			back = 0;
			arr[back] = x;
			size++;
		
		}
		else {
			back++;
			arr[back] = x;
			size++;
			
		}
		/* END_YOUR_CODE */
	}

	void delete_back() {
		/* BEGIN_YOUR_CODE */
		if (size == 0) {
			cout << "EMPTY" << endl;
		}
		else if (back == 0) {
			arr[back] = -1;
			back = 9999;
			size--;
		}
		else {
			arr[back] = -1;
			back--;
			size--;
		}
	
		/* END_YOUR_CODE */
	}

	void print_content() {
		/* BEGIN_YOUR_CODE */
		int temp;
		if (size == 0) {
			cout << "There is no array!" << endl;
			return;
		}
		for (temp = front; temp != (back + 1); temp = ((temp + 1) % 10000)) {
			if (arr[temp] == -1)
				continue;
			cout << arr[temp] << "  ";
		}
		
		/* END_YOUR_CODE */
	}
};


void Test(Vector v, EAC_vector eacv, int N, string test_type);


int main(int argc, char** argv)
{
	int N = 10000;

	if (argc == 2)
		N = atoi(argv[1]);

	cout << "N:\t" << N << "\n";

	Vector v;
	EAC_vector eacv;

	Test(v, eacv, N, "front");
	Test(v, eacv, N, "back");

	cout << endl << "End of test" << endl;
}


void Test(Vector v, EAC_vector eacv, int N, string test_type) {
	if (test_type == "front")
		cout << "\nTest case: insertion and deletion at FRONT\n\n";
	else
		cout << "\nTest case: insertion and deletion at BACK\n\n";

	// Insertion of integers
	double start_time;
	double elapsed_time_vector = 0;
	double elapsed_time_eacvector = 0;

	for (int i = 0; i < N; i++) {
		start_time = clock();
		if (test_type == "front")
			v.insert_front(i);
		else
			v.insert_back(i);
		elapsed_time_vector += clock() - start_time;

		start_time = clock();
		if (test_type == "front")
			eacv.insert_front(i);
		else
			eacv.insert_back(i);
		elapsed_time_eacvector += clock() - start_time;

	}

	cout << "\tInsertion time ratio (EAC_vector / vector):\t" << elapsed_time_eacvector / elapsed_time_vector << endl;

	// Deletion of integers
	elapsed_time_vector = 0;
	elapsed_time_eacvector = 0;

	for (int i = 0; i < N; i++) {
		start_time = clock();
		if (test_type == "front")
			v.delete_front();
		else
			v.delete_back();
		elapsed_time_vector += clock() - start_time;

		start_time = clock();
		if (test_type == "front")
			eacv.delete_front();
		else
			eacv.delete_back();
		elapsed_time_eacvector += clock() - start_time;

	}

	cout << "\tDeletion time ratio (EAC_vector / vector):\t" << elapsed_time_eacvector / elapsed_time_vector << endl;

	v.print_content();
	eacv.print_content();
}