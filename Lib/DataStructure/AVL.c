/*
    AVL-Tree (self-balancing binary search tree)


    Searh:
        average: O(logn)
    insert:
        average: O(logn)
    delete: 
        average: O(logn)

*/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int val;
    int height;
    int balFactor;
    struct Node* left;
    struct Node* right;
}node;


typedef struct AVL { // maybe don't need it
    node* root;
}AVL;


int max(int a, int b) {
    return a > b ? a : b;
}


node* createNode(int val) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = val;
    newNode->height = 0;
    newNode->balFactor = 0;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


int getHeight(node* root) {
    if (root != NULL) return root->height;
    else return -1;
}


void update(node* root) {
    if (root == NULL) return;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    root->height = max(leftHeight, rightHeight) + 1;
    root->balFactor = leftHeight - rightHeight;
}


node* rotateLL(node* A) {
    node* B = A->left;
    A->left = B->right;
    B->right = A;
    
    update(A);
    update(B);

    return B; 
}


node* rotateRR(node* A) {
    node* B = A->right;
    A->right = B->left;
    B->left = A;

    update(A);
    update(B);

    return B;
}


node* balance(node* root) {
    update(root); // before rotate, update

    if (root->balFactor > 1) { // L
        if (root->left && root->left->balFactor < 0) { // LR rotate
            root->left = rotateRR(root->left); // rotate left sub tree
        }
        return rotateLL(root); // rotate LL
    }
    if (root->balFactor < -1) { // R
        if (root->right && root->right->balFactor > 0) { // RL rotate
            root->right = rotateLL(root->right);
        }
        return rotateRR(root);
    }

    return root; // balanced well
}


node* insertRecursive(node* root, int val) {
    if (root == NULL) return createNode(val); // empty -> new one become the root
        
    if (root->val < val) root->right = insertRecursive(root->right, val);
    else if (root->val > val) root->left = insertRecursive(root->left, val);
    else return root;

    balance(root);
}


void insert(node* root, int val) {
    root = insertRecursive(root, val);
}


node* findMin(node* root) {
    node* cur = root;
    while (cur != NULL) {
        if (cur->left == NULL) break;
        cur = cur->left;
    }
    return cur;
}


node* deleteRecursive(node* root, int key) {
    if (root == NULL) return NULL;

    if (root->val < key) root->right = deleteRecursive(root->right, key);
    else if (root->val > key) root->left = deleteRecursive(root->left, key);
    else { // find
        node* del;

        if ((root->left == NULL) || (root->right == NULL)) {
            del = root->left ? root->left : root->right;

            if (del == NULL) {
                del == root;
                root = NULL;
            }
            else *root = *del; // copy child node
            free(del);
        }
        else { // has both child
            del = findMin(root->right);
            root->val = del->val; 
            root->right = deleteRecursive(root->right, del->val);
        }
    }

    if (root == NULL) return NULL;
    else return balance(root);
}


void delete(node* root, int key) {
    root = deleteRecursive(root, key);
}


void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}


void preorder(node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    inorder(root->left);
    inorder(root->right);
}


void postorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    inorder(root->right);
    printf("%d ", root->val);
}


