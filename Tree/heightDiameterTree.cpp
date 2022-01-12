/*
    Find height and diameter of a tree.
    Diameter is the longest distance(no: of nodes) between 2 nodes in a tree. It can pass through the root, or not.
    Approach: If it passes, then diameter = 1 + lHeight + rHeight. Else it will be the
    maximum oh lDiameter or rDiameter. 
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
    return 1 + max(height(root->left),height(root->right));
}

int diameter(node *root) {
    if(root == NULL)
        return 0;
    
    return max(1 + height(root->left) + height(root->right), max(diameter(root->left), diameter(root->right)));
} // Has n^2 complexity - if height is called for each of the nodes

int main() {

    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    
    */
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<< height(root) << endl;
    cout<< diameter(root);
    return 0;
}