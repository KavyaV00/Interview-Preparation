/*
    FLatten a binary to a linked list, in place such that the left of each node os null and the right points to the node in the order in which it comes in preorder.
*/

#include<iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void distKSubTree(node *n, int k) {
    if(k == 0) {
        cout<< n->data << " ";
        return;
    }

    if(n ==  NULL)
        return;

    if(n->left)
        distKSubTree(n->left,  k-1);
    if(n->right)
        distKSubTree(n->right, k-1);
}

void distKAncestor(node *root, node *n, int k) {
    
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);
    int k = 2;
    node* n = root->left;
    distKSubTree(n, k);
    return 0;
}