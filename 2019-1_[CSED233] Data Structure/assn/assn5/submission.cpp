#include <iostream>
/* BEGIN_YOUR_CODE
#include <WHATEVERYOUWANT>
 END_YOUR_CODE */

using namespace std;

/* BEGIN_YOUR_CODE */

// sample struct
struct TreeNode { /* It's up to you whether you use a binary tree structure or not.
						Personally, I recommend you to use a binary tree structure(k=2) for the sake of simplicity. */
	int element;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
	TreeNode* children[10];
	int cur = 0;
};

class tree {

public:
	tree() {
		root = new TreeNode;
		root->parent = NULL;
		root->element = 1;
		for (int i = 0; i < 10; i++) {
			 root->children[i] = NULL;
		}
		trueRoot = root;
	}
	void insert(TreeNode* p, int data) {
		TreeNode* temp = new TreeNode;
		temp->element = data;
		temp->parent = p;
		int i;
		for (i = 0; i < 10; i++) {
			temp->children[i] = NULL;
		}

		p->children[p->cur] = temp;
		p->cur++;
	}

	void convert(tree t, TreeNode* target) {
		
			TreeNode *temp = new TreeNode;
			TreeNode *temp2 = new TreeNode;
			if (target->parent == NULL)
				return;


			int i;
			int index, index2;

			for (i = 0; i < 10; i++) {
				if (target->children[i] == NULL) {
					index = i;
					break;
				}
			}
			temp = target->parent;
			temp2 = target->parent;

			for (i = 0; i < 10; i++) {
				if (temp->parent == NULL) {
					break;
				}
				if (temp->parent->children[i] == NULL) {
					index2 = i;
			    	break;
				}
			}

			target->parent = temp->parent;
			for (i = 0; i < 10; i++) {
				if (temp->parent != NULL) {
					temp->parent->children[index2] = target;
					if (temp->parent->children[i] == temp) {
						temp->parent->children[i] = NULL;
					}
				}
			}
			temp->parent = target;
			target->children[index] = temp;

			for (i = 0; i < 10; i++) {
				if (temp->children[i] == target) {
					temp->children[i] = NULL;
					break;
				}
			}

			convert(t, target);

			trueRoot = target;
			//parentToChild(target);

		
	}
	TreeNode* root;
	TreeNode* trueRoot;
	int depth = 0;
};

void printPreOrder(TreeNode* v)
{
	if (v == NULL)
		return;

	cout << v->element << "  "; fflush(stdout);

	for (int i = 0; i < 10; i++) {
		if (v->children[i] == NULL) {
			continue;
		}
		printPreOrder(v->children[i]);
	}
}

/* END_YOUR_CODE */

int main(int argc, char** argv)
{
	/* BEGIN_YOUR_CODE */
	tree t;
	tree t2;
	
	t.insert(t.root, 2);
	t.insert(t.root, 3);
	t.insert(t.root->children[0], 4);
	t.insert(t.root->children[0], 5);
	t.insert(t.root->children[0]->children[1], 6);
	t.insert(t.root->children[0] -> children[1], 7);
	
	/*
	             1
             2	     3
           4   5
	           6 7
	���� ���� ��ġ�� ���� ����� Ʈ���� �������.
	*/
	cout << "������ tree�� preorder traversal�� ���·� ����մϴ�." << endl;
	printPreOrder(t.trueRoot);
	cout << endl;
	
	
	cout << "convert�� ������ ������ tree�� ����մϴ�. root->children[0]->children[1]�� root�� �ǵ��� �Ͽ����ϴ�." << endl;
	t.convert(t, t.root->children[0]->children[1]); // 5�� �������� convert
	/*
		   5
	   6  7  2
			 4  1
				   3
	���� ���� ��ġ�� ���� ����� Ʈ���� ������� ���̴�.
	*/
	printPreOrder(t.trueRoot);
	cout << endl;
	

	t2.insert(t2.root, 2);
	t2.insert(t2.root, 3);
	t2.insert(t2.root->children[0], 4);
	t2.insert(t2.root->children[0], 5);
	t2.insert(t2.root->children[0]->children[1], 6);
	t2.insert(t2.root->children[0]->children[1], 7);
	/*
				 1
			 2	     3
		   4   5
			   6 7
	���� ���� ��ġ�� ���� ����� Ʈ���� �������.
	*/
	cout << "������ tree�� preorder traversal�� ���·� ����մϴ�." << endl;
	printPreOrder(t2.trueRoot);
	cout << endl;

	//
	cout << "convert�� ������ ������ tree�� ����մϴ�. root->children[0]�� root�� �ǵ��� �Ͽ����ϴ�." << endl;
	t2.convert(t2, t2.root->children[0]); // 2�� �������� convert
	/*
	       2
	 4    5    1
	      6 7    3
	���� ���� ��ġ�� ���� ����� Ʈ���� ������� ���̴�.
	*/

	printPreOrder(t2.trueRoot);
	cout << endl;

	
	cout << endl;


	/* END_YOUR_CODE */
	return 0;
}