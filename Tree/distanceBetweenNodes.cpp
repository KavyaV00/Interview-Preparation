/*
    Find shirtest distance between 2 nodes in the given tree.

    Approach: First find the LCA and then add the distance of 2 nodes from LCA.
*/

#include<iostream>
#include<vector>
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

node* LCA(node *root, int n1, int n2) {
    if(root == NULL)
        return NULL;
    
    node *leftRes = LCA(root->left, n1, n2);
    node *rightRes = LCA(root->right, n1, n2);

    if(leftRes && rightRes || root->data == n1 || root->data == n2) 
        return root;
    
    if(leftRes)
        return leftRes;
    return rightRes;
}

int findDist(node *root, int n, int dist) {
    if(root == NULL)
        return -1;
    
    if(root->data == n)
        return dist;

    int left = findDist(root->left, n, dist+1);
    if(left != -1)
        return left;
    
    return findDist(root->right, n, dist+1);
}

int shortestDistance(node *root, int n1, int n2) {
    node *lca = LCA(root, n1, n2);
    if(!lca)
        return -1;

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    
    return d1+d2;
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);
    int result = shortestDistance(root, 6, 3);
    if(result == -1)
        cout<< "Not found";
    else    
        cout<< result;
    return 0;
}