/*
    Find prime factotizaton of a number
*/

#include <iostream>
using namespace std;

void primefactor(int n) {
    int spf[n+1] = {0}, i, j, factor;
    cout<< "in fn";
    for(i=2; i<=n; i++) 
        spf[i] = i;
    
    for(i=2; i<=n; i++) {
        if(spf[i] == i) {
            for(j=2*i; j<=n; j+=i) {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    for(i=2; i<=n; i++) 
        cout<< spf[i] << " ";
    cout<< endl;
    while(n!=1) {
        factor = spf[n];
        cout<< factor << " ";
        n = n/factor;
    }
    return;
}

int main() {
    int n;
    cin>> n;
    primefactor(n);
    return 0;
}
