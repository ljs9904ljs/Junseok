#include<iostream>
using namespace std;


// Key: int, Value: char
class Entry {
	/* BEGIN_YOUR_CODE */
public:
	int key;
	char value;
	Entry* left;
	Entry* right;
	Entry* parent;
	Entry() {
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	bool isExternal() {
		return left == NULL && right == NULL;
	}
	bool isInternal() {
		return left != NULL || right != NULL;
	}

	/* END_YOUR_CODE */
};


class Iterator {
	/* BEGIN_YOUR_CODE */
public:
	Entry* v;
public:
	Iterator() {}
	Iterator(Entry* vv) : v(vv) {}
	const Entry& operator*() const { return *v; }
	Entry& operator*() { return *v; }
	bool operator==(const Iterator& p) const {
		return v == p.v;
	}
	bool operator!=(const Iterator& p) const {
		return v != p.v;
	}
	Iterator& operator++() {
		Entry* w = v->right;
		if (w->isInternal()) {
			do { v = w; w = w->left; } while (w->isInternal());
		}
		else {
			w = v->parent;
			while (v == w->right) {
				v = w; w = w->parent;
			}
			v = w;
		}
		return *this;
	}
	friend class OrderedMap_BST;
	/* END_YOUR_CODE */
};




// Ordered Map based on Binary Search Tree
class OrderedMap_BST {
private:
	/* BEGIN_YOUR_CODE */
	Entry* root;

	
	int size;
	int _k;
	int _v;
	Entry* tar;

	int ceil_k;
	char ceil_v;
	int lower_k;
	char lower_v;
	/* END_YOUR_CODE */


public:
	// Constructor
	/* BEGIN_YOUR_CODE */
	OrderedMap_BST() {
		root = NULL;
		_k = -1;
		ceil_k = -1;
		lower_k = -1;
	}
	
	void inorderFindKey(int k, Entry* v) { // 어떠한 key의 값을 가지고 그 key 값과 일치하는 node를 찾기 위해 inorder traversal
		if (v == NULL) {
			return;
		}

		inorderFindKey(k, v->left);

		if (v->key == k) {
			_k = v->key;
			_v = v->value;
			tar = v;

		}

		inorderFindKey(k, v->right);

	}

	void inorderCeiling(int k, Entry* v) { // ceiling의 값을 찾기 위해 inorder traversal
		if (v == NULL) {
			return;
		}
		inorderCeiling(k, v->right);
		if (v->key > k) {
			ceil_k = v->key;
			ceil_v = v->value;
		}
		inorderCeiling(k, v->left);
	}
	void inorderlower(int k, Entry* v) { // lower의 값을 찾기 위해 inorder traversal
		if (v == NULL) {
			return;
		}
		inorderlower(k, v->left);
		if (v->key < k) {
			lower_k = v->key;
			lower_v = v->value;
		}
		inorderlower(k, v->right);
	}

	const int& get_k() const {
		return _k;
	}
	int set_k(int kk) {
		_k = kk;
	}
	const char& get_v() const {
		return _v;
	}
	char set_v(char vv) {
		_v = vv;
	}

	void inorderPrint(Entry* v) { // inorder traversal을 하면서 트리를 출력한다. 
		if (v == NULL) {
			return;
		}

		inorderPrint(v->left);
		
		cout << "key: " << v->key << endl;

		inorderPrint(v->right);

	}

	void del_child_0(Entry* target) { // 삭제하려는 node의 child가 0개
		Entry* temp;
		temp = target->parent;
		if (temp == NULL) {
			root = NULL;
			delete target;
			return;
		}
		
		if (temp->left == target) {
			temp->left = NULL;
			delete target;
		}
		else if (temp->right == target) {
			temp->right = NULL;
			delete target;
		}
	}
	void del_child_1(Entry* target) { // 삭제하려는 node의 child가 1개
	
		if (target->left != NULL) { // child가 왼쪽에 있을 경우
			Entry* temp;
			temp = target->parent;
			if (temp == NULL) {
				target->key = target->left->key;
				target->value = target->left->value;
				Entry* temp2;
				temp2 = target->left;
				target->left = NULL;
				delete temp2;
				return;
			}
			if (temp->left == target) {
				temp->left = target->left;
				target->left->parent = temp;
				delete target;
			}
			else if (temp->right == target) {
				temp->right = target->left;
				target->left->parent = temp;
				delete target;
			}
		}
		else if (target->right != NULL) { // child가 오른쪽에 있을 경우
			Entry* temp;
			temp = target->parent;
			if (temp == NULL) {
				target->key = target->right->key;
				target->value = target->right->value;
				Entry* temp2;
				temp2 = target->right;
				target->right = NULL;
				delete temp2;
				return;
			}
			if (temp->left == target) {
				temp->left = target->right;
				target->right->parent = temp;
				delete target;
			}
			else if (temp->right == target) {
				temp->right = target->right;
				target->right->parent = temp;
				delete target;
			}
		}
	}
	void del_child_2(Entry* target) { // 삭제하려는 node의 child가 2개
		Entry* temp;
		Entry* temp2;
		temp = target->right;
		if (temp->left == NULL) {
			if (temp->right == NULL) {
				target->key = temp->key;
				target->value = temp->value;
				target->right = NULL;
				delete temp;
			}
			else {
				temp2 = temp->right;

				target->key = temp->key;
				target->value = temp->value;
				target->right = temp2;
				temp2->parent = temp->parent;
				delete temp;
			}
		}
		else {
			while (temp->left != NULL) {
				temp = temp->left;
			}
			target->key = temp->key;
			target->value = temp->value;
			temp2 = temp->parent;
			temp2->left = temp->right;
			if (temp2->left != NULL)
				temp->right->parent = temp2;

			delete temp;
		}
	}
	

	/* END_YOUR_CODE */


	void put(int k, char v) {
		/* BEGIN_YOUR_CODE */

		Entry* cur = new Entry;
		cur->left = cur->right = NULL;
		cur->key = k;
		cur->value = v;

		if (root == NULL) {
			cur->parent = NULL;
			root = cur;
		}
		else {
			Entry* temp = root;
			Entry* preTemp = root;

			while (1) {
				if (temp->key > cur->key) {
					//왼쪽으로 타고 내려감
					if (temp->left == NULL) {
						cur->parent = temp;
						temp->left = cur;
						return;
					}
					else {
						preTemp = temp;
						temp = temp->left;
					}
				}
				else {
					//오른쪽으로 타고 내려감
					if (temp->right == NULL) {
						cur->parent = temp;
						temp->right = cur;
						return;
					}
					else {
						preTemp = temp;
						temp = temp->right;
					}
				}
			}
		}
		/* END_YOUR_CODE */
	}


	void erase(int k) {
		/* BEGIN_YOUR_CODE */
		inorderFindKey(k, root);
		Entry* target = tar;

		if (_k == -1) {

			return;
		}
		else {


			if (target->left == NULL && target->left == NULL) { // 지울 entry의 child가 없다.
				del_child_0(target);
			}
			else if ((target->left != NULL && target->right == NULL) || (target->left == NULL && target->right != NULL)) { // 지울 entry의 child가 1개이다.
				del_child_1(target);
			}
			else { // 지울 entry의 child가 2개이다.
				del_child_2(target);
			}
		}
		
		/* END_YOUR_CODE */
	}


	char firstEntry() {
		// Return a value of the found iterator


		/* BEGIN_YOUR_CODE */
		Entry* temp;
		temp = root;

		while (temp->left != NULL) {
			temp = temp->left;
		}
		return temp->value;
		/* END_YOUR_CODE */
	}


	char ceilingEntry(int k) {
		// Return a value of the found iterator


		/* BEGIN_YOUR_CODE */
		inorderCeiling(k, root);
		return ceil_v;

		/* END_YOUR_CODE */
	}


	char lowerEntry(int k) {
		// Return a value of the found iterator


		/* BEGIN_YOUR_CODE */
		inorderlower(k, root);
		return lower_v;
		
		/* END_YOUR_CODE */
	}


	// Print keys in ascending order by tree search
	void printKeys() {
		/* BEGIN_YOUR_CODE */
		inorderPrint(root);
		/* END_YOUR_CODE */
	}


};




int main(int argc, char** argv)
{
	int keys[10] = { 6,14,4,8,12,2,18,10,16,0 };
	char values[10] = { 'G', 'O', 'E', 'I', 'M', 'C', 'S', 'K', 'Q', 'A' };
	int k1 = 7;
	int k2 = 9;


	OrderedMap_BST om = OrderedMap_BST();
	
	for (int i = 0; i < 10; i++) {
		om.put(keys[i], values[i]);
	}

	om.printKeys();

	cout << om.firstEntry() << endl;


	cout << om.ceilingEntry(k1) << endl;


	cout << om.lowerEntry(k1) << endl;


	for (int i = 0; i < 5; i++) {
		om.erase(keys[i]);
	}

	om.printKeys();


	cout << om.firstEntry() << endl;


	cout << om.ceilingEntry(k2) << endl;


	cout << om.lowerEntry(k2) << endl;




	for (int i = 5; i < 10; i++) {
		om.erase(keys[i]);
	}


	om.printKeys();


	cout << endl << "End of test" << endl;
}
