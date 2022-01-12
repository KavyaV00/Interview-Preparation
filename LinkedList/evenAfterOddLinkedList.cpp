/*
    Put even positions in after odd positions in the given array
    Eg:
     1->2->3->4->5->6->7->NULL becomes 1->3->5->7->2->4->6->NULL
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

void insert(node* &head,  int val) {
    node *newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
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

void evenAfterOdd(node* &head) {
    node *oddNode = head, *evenNode = head->next, *evenHead = head->next;
    while(evenNode != NULL && evenNode->next != NULL) {
        oddNode->next = evenNode->next;
        evenNode->next = evenNode->next->next;
        oddNode = oddNode->next;
        evenNode = evenNode->next;
    }
    oddNode->next = evenHead;
    
    display(head);
}

int main() {
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    display(head);
    evenAfterOdd(head);
}