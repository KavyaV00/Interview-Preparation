/*
    Find intersection point of 2 lists.
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

int length(node *head) {
    node *temp = head;
    int length = 0;
    while(temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

void intersect(node* &head1, node* &head2, int pos) {
    node *tail = head2, *intNode = head1;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    int i = 1;
    while(pos != i) {
        intNode = intNode->next;
        i++;
    }
    tail->next = intNode;
    display(head2); 
}

bool checkIntersection(node *head1, node *head2) {
    int l1 = length(head1), l2 = length(head2);
    node *temp1 = head1, *temp2 = head2;
    
    int diff = abs(l1-l2), i = 0;
    temp1 = head1; temp2 = head2;
    if(l1>l2) {
        while(diff!=0)  {
            temp1 = temp1->next;
            diff--;
        }
    }
    else if(l2>l1) {
         while(diff!=0)  {
            temp2 = temp2->next;
            diff--;
        }
    }
    while(temp1->next != NULL) {
        if(temp1 == temp2) {
            return true;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    } 
    return false;
}

int main() {
    node *head1 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    insertAtTail(head1, 7);
    display(head1);
    node *head2 = NULL;
    insertAtTail(head2, 1);
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    intersect(head1, head2, 5);
    cout<< checkIntersection(head1, head2);

    return 0;

}