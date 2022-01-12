/*
    Reverse a sentence using stack.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reverseSentence(string s) {
    stack<string> st;
    for(int i=0; i<s.length(); i++) {
        string word = "";
        while(s[i] != ' ' && i < s.length()) {
            word += s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()) {
        cout<< st.top() << " ";
        st.pop();
    }
    cout<< endl;
    return;
}

int main() {
    stack<int> st;
    string s = "Hello good morning";
    reverseSentence(s);
    return 0;
}


