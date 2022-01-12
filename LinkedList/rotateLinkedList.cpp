#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node(int val) {
        data = val;
        next=NULL;
    }
};

void insert(node* &head, int val) {
    node *newNode = new node(val);
    if(head==NULL) {
        head=newNode;
        return;
    }
    node *ptr=head;
    while(ptr->next!=NULL) {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    return;
}

void display(node *head) {
    if(head==NULL) {
        cout<< "NULL";
        return;
    }
    node *ptr=head;
    while(ptr!=NULL) {
        cout<< ptr->data << "->";
        ptr=ptr->next;
    }
    cout<< "NULL\n";
    return;
}

void rotate(node* &head,  node* &n, int &k) {
    if(n->next==NULL) {
        n->next=head;
        return;
    }
    rotate(head,n->next,k);
    k--;
    if(k==-0) {
        head=n->next;
        n->next=NULL;
    }
}

int main() {
    node *head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    int k=2;
    rotate(head,head,k);
    display(head);
    return 0;
}