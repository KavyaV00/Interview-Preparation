/*
    Find kth smallest element in a BST.
*/

#include <iostream>
#include <vector>
#include <stack>

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

void kthSmallest(node *root, int k) {
    stack<node*> v;
    node *ptr = root;
    int count = 0;
    node *x;
    cout<<"enter";
    do {
        while(ptr) {
            v.push(ptr);
            ptr = ptr->left;
        }
        
        ptr = v.top();
        v.pop();
        cout<< x->data;
        count++;
        if(count == k) {
            cout<< x->data;
            return;
        }
        ptr = ptr->right;
    }while(ptr);
    cout<<"return";
}

int main() {
    struct node *root = new node(3);
    root->left = new node(1);
    root->left->right = new node(2);
    root->right = new node(4);
    int k = 2;
    kthSmallest(root,1);
    
    return 0;
}