/*
    Find redundant paranthesis. 
    Example: 
    ((a+b)) --> 1
    (a+(a+b)) --> 0
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    cin>> s;
    stack<char> st;
    int count = 0;
    for(auto i : s) {
        if(i=='(' || i=='+' || i=='*')
            st.push(i);
        if(i == ')') {
            if(st.top() == '(') {
                count++;
                st.pop();
            }
            else {
                while(st.top()!='(') {
                    st.pop();
                }
                st.pop();
            }
        }
    }
    cout<< count;
    return 0;
}
