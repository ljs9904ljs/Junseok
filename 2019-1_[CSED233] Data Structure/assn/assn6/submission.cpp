#include<iostream>

using namespace std;
#define MAX_SIZE 100

struct pq_element {
	int prioirty;
	int value;
};

class heap_priority_queue {
private:
	pq_element heap[MAX_SIZE];
	/* BEGIN_YOUR_CODE */
	int size;
	/* END_YOUR_CODE */
public:
	heap_priority_queue() {
		size = 0;
	}
	/* BEGIN_YOUR_CODE */
	void insert(int prioirty, int value) {
		int i = 0;
		int temp;
		int temp2;

		heap[size].prioirty = prioirty;
		heap[size].value = value;

		for (i = 0; i < size; i++) { //bubble sort같은 방식으로 우선순위가 높은 것을 앞으로 보낸다.
			for (int j = 0; j < size; j++)
			{
				if (heap[j].prioirty < heap[j+1].prioirty) {
					temp = heap[j].prioirty;
					heap[j].prioirty = heap[j+1].prioirty;
					heap[j+1].prioirty = temp;

					temp2 = heap[j].value;
					heap[j].value = heap[j+1].value;
					heap[j+1].value = temp2;
				}
			}
		}
		size++;

	} // insert element
	/* END_YOUR_CODE */

	/* BEGIN_YOUR_CODE */
	void removeMax() {
		int i;
		if (empty()) {//비어있으면 우선순위가 가장 큰 것을 제거하는 행동을 하지 않는다.
			return;
		}
		for (i = 1; i < size; i++) { //뒤에있는 걸 앞에 있는 걸로 복사하면서 맨 앞에 있는 것을 지운다.
			heap[i-1] = heap[i];
		}	
		size--;
	} // remove a pq_element having maximum prioirty
	/* END_YOUR_CODE */

	/* BEGIN_YOUR_CODE */
	pq_element max() { //가장 큰 우선 순위를 가지고 있는 0번 칸의 값을 반환한다.
		if (empty()) { //비어있으면 하지 않는다.
		}
		else
			return heap[0];
	} // return a pq_element having maximum prioirty
	/* END_YOUR_CODE */

	/* BEGIN_YOUR_CODE */
	bool empty() { //size가 0이라면 1을 리턴
		return size == 0;
	} // is it empty?
	/* END_YOUR_CODE */
};

int main(int argc, char** argv) {
	int N;
	cin >> N; // the number of elements to insert in priority queue

	heap_priority_queue pq;

	for (int i = 0; i < N; ++i) {
		int value, priority;
		cin >> priority >> value;
		pq.insert(priority, value);
	}

	while (!pq.empty()) {
		cout << pq.max().value << " ";
		pq.removeMax();
	}

	return 0;
}