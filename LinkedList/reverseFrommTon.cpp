/*
    Reverse a linked list from position m to n. Do it in-place and in one-pass.
    For example:
    Given 1->2->3->4->5->NULL, m = 2 and n = 4,
    return 1->4->3->2->5->NULL.
*/


  

#include <iostream>
#include <string>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left == right){
        return head;
    }
    
    if(head == NULL){
        return NULL;
    }
    
    ListNode* temp = head;
    ListNode* start = NULL;
    for(int i=1; i<left; i++){
        start = temp;
        temp = temp->next;
    }
    
    ListNode* prev = NULL;
    ListNode* end = temp;
    for(int i=left; i<=right; i++){
        ListNode* x = temp->next;
        temp->next = prev;
        prev = temp;
        temp = x;
    }
    
    end->next = temp;
    if(start != NULL){
        start->next = prev;
        return head;
    }
    return prev;
}