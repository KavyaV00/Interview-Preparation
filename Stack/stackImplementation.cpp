#include <iostream>
using namespace std;

#define SIZE 10

class stack {
    int* arr;
    int top;

    public:
    stack() {
        arr = new int[SIZE];
        top = -1;
    }

    void push(int x) {
        if(isFull()) {
            cout<< "Stack overflow" << endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop() {
        if(isEmpty()) {
            cout<< "No element to pop" << endl;
            return;
        }

        cout<< arr[top] << endl;
        top--;
    }

    void peek() {
        if(isEmpty()) {
            cout<< "No element in stack" << endl;
            return;
        }
        
        cout<< arr[top] << endl;
    }

    bool isEmpty() {
        if(top == -1)
            return true;
        return false;
    }

    bool isFull() {
        if(top == SIZE-1)
            return true;
        return false;
    }
};

int main() {
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.peek();
    st.pop();
    cout<< st.isEmpty() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout<< st.isEmpty() << endl;
    return 0;
}
