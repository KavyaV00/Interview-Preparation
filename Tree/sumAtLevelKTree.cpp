/*
    Find the sum of all the nodes of a tree at a level k.
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

int findSumAtK(node *root, int k) {
    int sum = 0, level = 0;
    if(root == NULL) {
        return -1;
    }

    queue<struct node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        struct node *node = q.front();
        
        q.pop();
        if(node !=NULL) {
            if(level == k) 
                sum += node->data;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty()) {
            level++;
            q.push(NULL);
        }
    }
    return sum;
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<< findSumAtK(root,1);
    return 0;
}