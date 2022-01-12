/*
    
    Check if a cycle/ loop is present in a given linked list. If present, then remove the cycle. 
    
    Here we use Floyd’s cycle detection method/ hare and tortoise method/ 2 pointer method.
    
    Approach(for detection): slow and fast pointers are initially at the head of the linked list. slow pointer takes one step forward, and fast pointer takes two-steps at a time. If the 2 meet at some point, then a cycle is detected. 

    Approach(for correction): After detection, any one pointer is moved to point to the head of the list, say slow. Both the pointers then move one-step forward at a time. When the next of both pointers point to the same node, this indicates the start of the cycle. Now the next of the fast pointer is made NULL to break the cycle/ loop.

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

void makeCycle(node* &head, int pos) {
    node *cycleStart = NULL;
    node *temp = head;
    int count=0;
    while(temp->next != NULL) {
        if(count == pos) 
            cycleStart = temp;
        temp = temp->next;
        count++;
    }
    temp->next = cycleStart;
}

bool detectCycle(node *head) {
    node *slow = head, *fast = head;
    while(fast != NULL || fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

void removeCycle(node* &head) {
    if(!detectCycle(head)) {
        cout<< "No cycle" << endl;
        return;
    }
    node *slow = head, *fast = head;
    while(fast != NULL || fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            fast = head;
            break;
        }
    }
    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
    display(head);
}

int main() {
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    display(head);
    makeCycle(head, 4);
    // display(head); // 1->2->3->4->5->6->7->8->5->6->7->8->5->6->7->8->5->6->.....
    cout<< detectCycle(head) <<endl;
    removeCycle(head);
    // display(head);
    return 0;
}