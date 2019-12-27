#include<iostream>


typedef struct bunch {
    int data;
    int key;
} bunch;

typedef struct node {
    bunch pair;
    struct node *left, *right;
} node;

node* newNode(bunch item) {
    node* temp = new node;
    temp->pair.data = item.data;
    temp->pair.key = item.key;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d : %d \n", root->pair.key, root->pair.data);
        inorder(root->right);
    }
}

node* insert(node* node, bunch item) {
    if(node == NULL) return newNode(item);

    if(item.key < node->pair.key)
        node->left = insert(node->left, item);
    else if(item.key > node->pair.key)
        node->right = insert(node->right, item);
    
    return node;
}

node* search(node* root, bunch item) {
    if(root == NULL || root->pair.key == item.key)
        return root;

    if(root->pair.key < item.key) {
        return search(root->right, item);
    }
    
    return search(root->left, item);
}

int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, bunch{23, 50}); 
    insert(root, bunch{1, 30}); 
    insert(root, bunch{2, 20}); 
    insert(root, bunch{4, 40}); 
    insert(root, bunch{123, 70}); 
    insert(root, bunch{24, 90}); 
    insert(root, bunch{7241, 80}); 
   
    // print inoder traversal of the BST 
    inorder(root); 
   
    return 0; 
}