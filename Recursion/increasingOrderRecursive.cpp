/*
    Print all numbers in increasing/ decreasing order till n recursively.
*/

#include <iostream>
using namespace std;

void inc(int n) {
    if(n==0)
        return;
    inc(n-1);
    cout<< n << endl;
}

void inc2(int i, int n) {
    if(i>n)
        return;
    cout<< i << endl;
    inc2(i+1, n);
}

void dec(int n) {
    if(n==0)
        return;
    cout<< n << endl;
    dec(n-1);
}

int main() {
    int n;
    cin>> n;
    // inc(n);
    inc2(1,n);
    dec(n);
    return 0;
}