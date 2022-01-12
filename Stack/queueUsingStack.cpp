/*
    Implement a queue using stack
*/

#include <iostream>
#include <stack>
using namespace std;

class que {
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x) {
        s1.push(x);
    }
    void pop() {
        if(s1.empty()){
            cout<< "Queue empty!";
            return;
        }
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        cout<< s2.top() << endl;
        s2.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void print() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        while(!s2.empty()) {
            cout<< s2.top() <<" ";
            s1.push(s2.top());
            s2.pop();
        }
        cout<< endl;
    }
};

int main() {

    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);  
    q.push(5);
    q.push(6);
    q.print();
    q.pop();
    q.pop();
    q.print();
    return 0;
}
