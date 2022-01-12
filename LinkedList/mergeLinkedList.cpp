/*
    Merge 2 sorted linked lists.
*/

#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node *next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

void insert(node* &head, int val) {
    node *newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp->next != NULL) 
        temp = temp->next;
    temp->next = newNode;
}

void display(node *head) {
    node *temp = head;
    while(temp != NULL) {
        cout<< temp->data << "->";
        temp = temp->next;
    }
    cout<< "NULL" << endl;
}

node* merge(node* &head1, node* &head2) {
    node *p1 = head1, *p2 = head2;
    node *dummyNode = new node(-1);
    
    node *p3 = dummyNode;
    while(p1 != NULL && p2 != NULL) {
        if(p1->data < p2->data) {
            p3->next = p1;
            p1 = p1->next;
        }
        else {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while(p1 != NULL) {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while(p2 != NULL) {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummyNode->next;
}

node *mergeRecursive(node *head1, node *head2) {
    node *result;
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    if(head1->data < head2->data) {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}

int main() {
    node *head1 = NULL, *head2 = NULL;
    insert(head1, 1);
    insert(head1, 3);
    insert(head1, 5);
    insert(head1, 7);
    insert(head2, 2);
    insert(head2, 4);
    insert(head2, 6);
    insert(head2, 8);
    display(head1);
    display(head2);
    // node *newHead1 = merge(head1, head2);
    // display(newHead1);
    node *newHead2 = mergeRecursive(head1, head2);
    display(newHead2);
    return 0;
}