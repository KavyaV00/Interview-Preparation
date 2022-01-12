/*
    Check if the given tree is height balanced or not. 
    Height balanced - for each node, the difference between heights of left and right subtress must be <= 1 
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

int height(node *root) {
    if(root == NULL) 
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int isHeightBalanced(node *root) {
    if(root == NULL)
        return true;

    if(!isHeightBalanced(root->left)) 
        return false;
    if(!isHeightBalanced(root->right))
        return false;

    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int diff = abs(lHeight - rHeight);
    if(diff <= 1)
        return true;
    else 
        return false; 
} // isHeightBalanced function called for each node in tree. So O(n). Each time, within the fucntion height() is being called, which has O(n). Thus the final time complexity will be O(n*n) = O(n^2).

int isHeightBalanced_(node *root, int *height) {
    if(root == NULL)
        return true;
    int lh = 0, rh = 0;
    if(!isHeightBalanced_(root->left, &lh)) 
        return false;
    if(!isHeightBalanced_(root->right, &rh))
        return false;
    
    *height = max(lh, rh) + 1;
    if(abs(lh - rh) <= 1)
        return true;
    else 
        return false; 
}


int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    if(isHeightBalanced(root))
        cout<< "Yes\n";
    else    
        cout<< "No\n";
    int height = 0;
    if(isHeightBalanced_(root, &height))
        cout<< "Yes\n";
    else    
        cout<< "No\n";
    return 0;
}