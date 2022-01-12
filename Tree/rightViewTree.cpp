/*
    Print right view of a binary tree.

    Approach: Perform Level Order Traversal. Print the last element at each level.
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

void rightView(node* root) {
    if(root == NULL) 
        return;
    
    queue<node*> q;
    q.push(root);
    
    int n, i;
    while(!q.empty()) {
        n = q.size();
        for(i=0; i<n; i++) {
            node* curr = q.front();
            q.pop();

            if(i == n-1)
                cout<< curr->data << " ";
        
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
        }    
    }
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    rightView(root);
    return 0;
}