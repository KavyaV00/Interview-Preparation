// Find the length of longest arithmetic subarray of a given array
// Arithmetic subarray - has a sequence of numbers with equal difference between them

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int i, j, n;
    cin>> n;
    int arr[n];
    for(i=0; i<n; i++) 
        cin>> arr[i];

    int length, diff, maxlen = 0;

    // Approach 1
    // int b[n];
    // for(i=0; i<n-1; i++)
    //     b[i] = abs(arr[i] - arr[i+1]);

    // for(i=0; i<n-1; i++) 
    //     cout<< b[i]<< " ";
    // cout<< endl;
    // for(i=0; i<n-1; i++) {
    //     length = 1;
    //     while(b[i]==b[i+1]) {
    //         length++;
    //         cout<< "j: " << j << "\tlength: " << length << endl;
    //         i++;
    //     }
    //     maxlen = (max(maxlen, length+1));
    // }
    // cout<< "Final: " << maxlen;

    // Approach 2
    diff = arr[1] - arr[0];
    length = 2;
    i = 2;
    while(i<n) {
        if(abs(arr[i]-arr[i-1]) == diff) 
            length++;
        else {
            diff = abs(arr[i]-arr[i-1]);
            length = 2;
        }
        maxlen = max(maxlen, length);
        i++;
    }
    cout<<"maxlen: "<<maxlen;
    return 0;
    
}
