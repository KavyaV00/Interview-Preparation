/*
    Generate the maximum circular sum subarray of a given array
*/

#include <iostream>
using namespace std;

int main() {
    int i, j , n;
    cin>> n;
    int arr[n];
    for(i=0; i<n; i++) 
        cin>> arr[i];
    int maxGlobal = 0, maxCurrent = 0;
    for(i=0; i<i+(n-1)%n; i++) {
        cout<< "i: " << i;
        maxCurrent = max(arr[i], maxCurrent + arr[i]);
        if(maxCurrent > maxGlobal) 
            maxGlobal = maxCurrent;
    }
    cout<< maxGlobal;
    return 0;
}
