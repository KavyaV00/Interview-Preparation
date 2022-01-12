/*
    Add the last k nodes to the head of the given list.

    Approach: Traverse the list. When you find the node at position (length - k), set the newHead and newTail pointers accordingly. After traversal, change the pointers to indicate their new positon in the list.
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

void addLastK(node* &head, int k) {
    int length = 0;
    node *temp = head, *newTail = NULL, *newHead = NULL;
    while(temp != NULL) {
        temp = temp->next;
        length++;
    }
    int pos = length - k;
    cout<< pos << endl;
    int count = 1;
    temp = head;
    while(temp->next != NULL) {
        
        if(count == pos) {
            newTail = temp;
            newHead = temp->next;
        }
        temp = temp->next;
        count++;
    }
    temp->next = head;
    newTail->next = NULL;
    head = newHead;
    display(head);
    return;
}

int main() {

    node *head = NULL;
    int k;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    display(head);
    cin>> k;
    addLastK(head, k);
}