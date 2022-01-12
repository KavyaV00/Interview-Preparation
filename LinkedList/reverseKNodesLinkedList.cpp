/*
    Given a linked list and an integer K. Reverse the nodes of a linked list k at a time
    and return its modified list. If the number of nodes is not a multiple of K then
    left-out nodes, in the end, should remain as it is.
    Idea: There are 2 cases:
        1. The size of the linked list is less than K. In this case, return the list as it is.
        2. The size of the linked list is more than K. Reverse the first K nodes and recurse for the remaining list.
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

void insertAtHead(node* &head, int val) {
    node *new_node = new node(val);
    new_node->next = head;
    head = new_node;
    return;
}

void insertAtTail(node* &head, int val) {
    
    node *new_node = new node(val);
    if(head == NULL) {
        head = new_node;
        return;
    }
    node *temp = head;
    while(temp->next != NULL) 
        temp = temp->next;
    temp->next = new_node;
    return;
}

void display(node *head) {
    node *temp = head;
    while(temp!=NULL) {
        cout<< temp->data << "->";
        temp = temp->next;
    }
    cout<< "NULL" << endl;
    return;
}

bool search(node *head, int val) {
    node *temp = head;
    while(temp!=NULL) {
        if(temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

node* reverseK(node *head, int k) {
    node *prev = NULL, *next, *curr = head;
    int count = 0;
    while(count<k && curr!=NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!= NULL) {
        head->next = reverseK(next, k);
    }
    return prev;
}

int main() {
    node *head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 1);  
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    display(head);
    node *newH = reverseK(head, 2);
    display(newH);
    return 0;

}