#include <iostream>
using namespace std;
 
// A Linked List Node
struct Node
{
    int data;
    Node* next;
 
    // Constructor
    Node(int data) {
        this->data = data;
    }
};
 
// Helper function to allocate the new node in a heap and
// insert it at the beginning of the linked list
void push(Node* &headRef, int data)
{
    Node* node = new Node(data);
    node->next = headRef;
    headRef = node;
}
 
// Helper function to print a given linked list
void printList(string msg, Node* head)
{
    cout << msg << ": ";
    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
 
    cout << "nullptr" << endl;
}
 
// Function to reverse first `k` nodes in a linked list.
// Note that the linked list pointer is passed by reference.
// The function returns the new front node (or last node in the original sublist)
Node* reverse(Node* &curr, int k)
{
    // maintain a `prev` pointer
    Node* prev = nullptr;
 
    // traverse the list and reverse first `k` nodes
    while (curr && k--)
    {
        // tricky: note the next node
        Node* next = curr->next;
 
        // fix the `curr` node
        curr->next = prev;
 
        // advance the two pointers
        prev = curr;
        curr = next;
    }
 
    // return node at the front
    return prev;
}
 
// Function to skip `k` nodes in a given linked list.
// Note that the linked list pointer is passed by reference.
void skipKNodes(Node* &curr, int k)
{
    while (curr && k--) {
        curr = curr->next;
    }
}
 
// Recursive function to reverse every alternate group of `k` nodes
// in a linked list
Node* reverseAlternatingKNodes(Node* head, int k)
{
    // base case
    if (head == nullptr) {
        return nullptr;
    }
 
    Node* originalHead = head;
 
    // reverse first `k` nodes
    Node* curr = head;
    head = reverse(curr, k);
 
    // link original head node with the current node ((k+1)'th node)
    originalHead->next = curr;
 
    // skip next `k-1` nodes
    skipKNodes(curr, k - 1);
 
    // recur for the remaining list and link it to the current node
    if (curr) {
        curr->next = reverseAlternatingKNodes(curr->next, k);
    }
 
    // return head node
    return head;
}
 
int main()
{
    // construct a singly linked list
    Node* head = nullptr;
 
    int n = 10;
    while (n) {
        push(head, n--);
    }
 
    int k = 2;
 
    printList("Original linked list ", head);
    head = reverseAlternatingKNodes(head, k);
    printList("Resultant linked list", head);
 
    return 0;
}


