/*
    FLatten a binary to a linked list, in place such that the left of each node is null and the right points to the node in the order in which it comes in preorder.
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

void inorder(node *root) {
    if(root == NULL) 
        return;
    
    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}

void flattenTree(node *root) {
    if(root == NULL || !root->left && !root->right)
        return;

    if(root->left) {
        flattenTree(root->left);

        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *t = root->right;
        while(t->right != NULL)
            t =  t->right;

        t->right = temp;
    }

    flattenTree(root->right);
}

void flatten(node *root) {
    if(root == NULL)
        return;

    node *prev = NULL;

    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;

    prev = root;
} 


int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);
    inorder(root);
    flattenTree(root);
    inorder(root);
    return 0;
}