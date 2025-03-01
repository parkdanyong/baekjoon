/*
    Binary Search Tree
    

    Searh:
        average: O(logn)
        worst: O(n)
    insert:
        average: O(logn)
        worst: O(n)
    delete: 
        average: O(logn)
        worst: O(n)
    

    I'll update to handle multiple val types.

    preorder
    inorder
    postoder

*/


#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h> // can be used to return success/failure


typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
}node;


node* createNode(int val) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


void search(node* root, int target, node* des) {
    if (root== NULL) { // empty
        des = NULL;
        return;
    }


    node* cur = root;
    while (cur != NULL) {
        if (cur->val < target) cur = cur->right;
        else if (cur->val > target) cur = cur->left;
        else { // find
            des = cur;
            return;
        }
    }
    
    des = NULL;
}


void findParent(node* root, node* target, node* des) {
    if (root== NULL) { // empty
        des = NULL;
        return;
    }


    node* cur = root;
    while (cur != NULL) {
        if (cur->val < target->val) {
            if (cur->right == target) {
                des = cur;
                return;
            }
            else cur = cur->right;
        }
        else {
            if (cur->left == target) {
                des = cur;
                return;
            }
            else cur = cur->left;
        }
    }
    
    des = NULL;
}


node* findMin(node* root) {
    node* cur = root;
    while (cur != NULL) {
        if (cur->left) cur = cur->left;
        else return cur;
    }

    return NULL;
}


node* findMax(node* root) {
    node* cur = root;
    while (cur != NULL) {
        if (cur->right) cur = cur->right;
        else return cur;
    }

    return NULL;
}


void insert(node* root, int val) {
    node* newNode = createNode(val);
    if (root == NULL) { // empty
        root = newNode;
        return;
    }


    node* cur = root;
    while (cur != NULL) {
        if (cur->val < val) { // right
            if (cur->right == NULL) {
                cur->right = newNode;
                break;
            }
            else cur = cur->right;
        }   
        else { // left
            if (cur->left == NULL) {
                cur->left = newNode;
                break;
            }
            else cur = cur->left;
        }
    }
}


void delete(node* root, int target, int* des) {
    if (root == NULL) { // empty
        des = NULL;
        return;
    }


    node* del;
    node* parent;
    node* cur = root;
    while (cur != NULL) {
        if (cur->val < target) {
            parent = cur;
            cur = cur->right;
        }
        else if (cur->val > target) {
            parent = cur;
            cur = cur->left;
        }
        else { // find
            del = cur;
            if (cur->left && cur->right) {
                node* successor = findMin(cur->right);
                cur->val = successor->val;
                del = successor;
                findParent(cur->right, successor, parent);
                if (successor->right) parent->left = successor->right;  
            }
            else if (cur->left) {
                if (parent->left == cur) parent->left = cur->left;
                else parent->right = cur->left;
            }
            else {
                if (parent->left == cur) parent->left = cur->right;
                else parent->right = cur->right;
            }
            free(del);
            *des = target;
            return;
        }
    }

    *des = 0;
}



void clearBST(node* root) {
    if (root == NULL) return;

    node* cur = root;
    clearBST(cur->left);
    clearBST(cur->right);
    free(cur);
}