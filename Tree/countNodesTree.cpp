/*
    COunt number of nodes in a tree.

    Aproach: Recursive. 
    retrun 1 + left subtree count + right subtree count
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

int countNodes(node *root) {
    if(root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<< countNodes(root);
    return 0;
}