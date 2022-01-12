// Print all prime numbers in a given range
#include <iostream>
using namespace std;

int main() {
    int a, b, i, j, num, flag=0;
    cout<< "Enter a: ";
    cin >> a;
    cout<< "Enter b: ";
    cin>> b;
    cout<< "Prime numbers between " << a << " and " << b <<" are: ";
    for(i=a; i<=b; i++) {
        for(j=2; j<i; j++) {
            if(i%j == 0) {
                break;
            }
        }   
        if(i == j) 
            cout << i<< "  ";
    }
    return 0;
}
