/*
    Find the sum of all nodes in a binary tree.
*/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int sumNodes(node *root) {
    if(root->left == NULL && root->right == NULL) 
        return root->data;
    if(root == NULL)
        return 0;
    
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}


int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<< sumNodes(root);
    return 0;
}