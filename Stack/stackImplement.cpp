#include <iostream>
using namespace std;
#define MAX 5

struct stack {
    int items[MAX];
    int TOP = -1;
};

typedef struct stack stack;
void createStack(stack *st) {
    st->TOP = -1;
}

int isEmpty(stack *st) {
    return (st->TOP == -1);
}

int isFull(stack *st) {
    return (st->TOP == MAX - 1);
}

void push(stack *st, int data) {
    if(!isFull(st)) {
        st->TOP++;
        st->items[st->TOP] = data;
    }
    else
        cout<< "Stack full\n";
}

void pop(stack *st) {
    if(!isEmpty(st)) {
        st->TOP--;
    }
    else 
        cout<< "Stack empty\n";
}

void peek(stack *st) {
    if(isEmpty(st)) {
        cout<< "Stack empty\n";
        return;
    }
    cout<< st->items[st->TOP] << endl;
}

void printStack(stack *st) {
    if(isEmpty(st)) {
        cout<< "Stack empty\n";
        return;
    }
    for(int i=0; i<=st->TOP; i++)
        cout<< st->items[i] << "\t";
    cout<< endl;
}

int main() {

    stack *st = (stack*)malloc(sizeof(stack));
    createStack(st);
    push(st, 1);
    push(st, 2);
    push(st, 3);
    push(st, 4);
    push(st, 5);
    push(st, 6);
    printStack(st);
    pop(st);
    peek(st);
    printStack(st);
    return 0;
}
