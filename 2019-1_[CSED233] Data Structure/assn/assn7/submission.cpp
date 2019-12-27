#include<iostream> 
#include <list> 
using namespace std;

class Hash
{
	int BUCKET;
	list<int> *table;
public:
	Hash(int V);
	void put(int key);
	void erase(int key);
	int hashFunction(int x) {
		/* BEGIN_YOUR_CODE */
		return ((3 * abs(x) + 1) % BUCKET);
		/* END_YOUR_CODE */
	}
	void showHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::put(int key)
{
	/* BEGIN_YOUR_CODE */
	table[hashFunction(key)].push_back(key);
	/* END_YOUR_CODE */
}

void Hash::erase(int key)
{
	/* BEGIN_YOUR_CODE */
	list<int>::iterator iter;
	for (iter = table[hashFunction(key)].begin(); iter != table[hashFunction(key)].end(); ++iter) {
		if (*iter == key) {
			table[hashFunction(key)].erase(iter);
			break;
		}
	}

	/* END_YOUR_CODE */
}

void Hash::showHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " -> " << x;
		cout << endl;
	}
}

int main()
{
	int input[] = { 8, 81, 50, 77, 9, 34, 102, 95, 367, 25, 13, 254, 100, 76, 24 };
	int n = sizeof(input) / sizeof(input[0]);

	Hash h(13);
	for (int i = 0; i < n; i++)
		h.put(input[i]);
	h.showHash();

	cout << "After erasing keys =======" << endl;

	h.erase(102);
	h.erase(254);
	h.erase(76);

	h.showHash();
	system("pause");
	return 0;
}