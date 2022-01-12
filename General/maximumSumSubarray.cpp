/*
    Find maximum sum subarray of a given array.

    KADANE'S ALGORITHM
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
    for(i=0; i<n; i++) {
        maxCurrent = max(arr[i], maxCurrent + arr[i]);
        if(maxCurrent > maxGlobal) 
            maxGlobal = maxCurrent;
    }
    cout<< maxGlobal;
    return 0;
}
