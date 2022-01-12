#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

struct node {
    int data;
    node *next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

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

node* merge(node* &head1, node *&head2) {
    // if(head1==NULL || head1->next==NULL) {
    //     return head;
    // }
    node *newH;
    if(head1->data<head2->data) {
        newH= head1;
        head1=head1->next;
    }
    else {
        newH= head2;
        head2=head2->next;
    }
    node* temp = newH;
    while(head1 && head2) {
        if(head1->data<head2->data) {
            temp->next = head1;
            head1=head1->next;
            temp=temp->next;
        }
        else {
            temp->next = head2;
            head2=head2->next;
            temp=temp->next;
        }
    }
    while(head1) {
        temp->next=head1;
        head1=head1->next;
        temp=temp->next;
    }
    while(head2) {
        temp->next=head2;
        head2=head2->next;
        temp=temp->next;
    }

    return newH;
}

node* sort(node* head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    node *slow=head, *fast=head;
    while(fast->next && fast->next->next) {
        slow=slow->next;
        fast=fast->next->next;
    }
    node *mid = slow->next;
    slow->next = NULL;
    display(head);
    head=sort(head);
    mid=sort(mid);
    node *newH = merge(head, mid);
    return newH;

}

int main() {

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 7);
    insertAtTail(head, 6);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 8);
    insertAtTail(head, 10);
    // display(head);
    node *newH = sort(head);
    display(newH);
}