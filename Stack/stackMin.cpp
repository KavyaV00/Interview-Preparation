/*
    Find min element of stack. Keep an integer - but if it gets popped, we have to search entire array to get the next min. 
    Better, store the min along with the value of top. But, this will consume large spacea s data size increases.
    Even better, have another stack to stoe min values.
*/

#include <iostream>
#include <stack>
using namespace std;

void push(stack<int> &s1, stack<int> &s2, int value) {
    if(s2.empty() || value <= s2.top())
        s2.push(value);
    s1.push(value);
}

void pop(stack<int> &s1, stack<int> &s2) {
    if(s1.top() == s2.top())
        s2.pop();
    s1.pop();
}

int getMin(stack<int> &s2) {
    if(s2.empty())
        return 0;
    return s2.top();
}

int main() {
    stack<int> s1, s2;
    push(s1, s2, 6);
    cout<< getMin(s2);
    push(s1, s2, 3);
    cout<< getMin(s2);
    push(s1, s2,  4);
    cout<< getMin(s2);
    push(s1, s2, 1);
    cout<< getMin(s2);
    pop(s1, s2);
    cout<< getMin(s2);

    return 0;
    
}