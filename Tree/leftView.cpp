/*
    Print lef view of a binary tree.

    Approach:
*/

#include<iostream> 
#include<queue>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;

    node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void leftView(struct node *root) {
    if(root == NULL)
        return;
    
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        

        int n, i;
        n = q.size();
        for(i=0;i<n;i++) {
            node *curr = q.front();
            q.pop();
            if(i==n-1) {
                cout<< curr->data << " ";
            }
            if(curr->right)
                q.push(curr->right);
            if(curr->left)
                q.push(curr->left);
        }
    }
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);
    root->left->left->right = new node(6);
    leftView(root);
    
}