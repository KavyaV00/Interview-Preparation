/*
    Reverse a stack.

    Appoach: Instead of using a new stack to store the popped elements, we can use recursion to reverse the same stack.
*/

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int x) {
    if(st.empty()) {
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(y);
}

void reverseStack(stack<int> &st) {
    if(st.empty()) 
        return;
    int x = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,x);
    // st.pop();
} 

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    while(!st.empty()) {
        cout<< st.top() << " ";
        st.pop();
    }
}
