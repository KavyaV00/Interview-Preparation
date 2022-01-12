/*
    Find the lowest common ancestor of 2 nodes in the given tree.
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

bool getPath(node* root, int num, vector<int> &path) {

    if(root == NULL)
        return false;

    path.push_back(root->data);
    if(root->data == num)
        return true;
    
    if(getPath(root->left, num, path) || getPath(root->right, num, path)) {
        return true;
    }
    path.pop_back();
    return false;
}

int LCA2(node *root, int n1, int n2) {
    vector<int> path1, path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2))
        return -1;

    int pc;
    for(pc=0; pc<path1.size() && pc<path2.size(); pc++) {
        if(path1[pc] != path2[pc])
            break;
    }

    return path1[pc-1];
}

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

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);
    struct node *result = LCA(root, 6, 5);
    if(result)
        cout<< result->data<< endl;
    else    
        cout<< "Element not found";

    int res = LCA2(root, 6, 5);
    if(res == -1)
        cout<< "Not found";
    else    
        cout<< res;
    return 0;
}