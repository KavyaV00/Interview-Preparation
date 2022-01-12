/*
    Sieve of Eratosthenes
*/

#include <iostream>
using namespace std;

void sieve(int n) {
    int prime[n] = {0}, i, j;
    
    for(i=2; i<n; i++) {
        if(prime[i] == 0) {
            for(j=2*i; j<n; j+=i) 
                prime[j] = 1;
        } 
    }
    for(i=2; i<n; i++) 
        if(prime[i] == 0)
            cout<< i << " ";
    cout<< endl;
    return;
}

int main() {
    int n;
    cin>> n;
    sieve(n);
    return 0;
}
