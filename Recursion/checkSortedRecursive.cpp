/*
    Check whether an array is sorted (strctly increasing) using recursion.
    Array sorted if:
        arr[0] < arr[1] and 
        rest of the array is sorted.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSorted( int arr[], int n) {
    
    if(n == 1)
        return true;
    bool restArray = isSorted(arr+1, n-1);
    if(arr[0] < arr[1] && restArray)
        return true;
    else    
        return false;
}

int main() {
    int n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>> arr[i];

    cout<< isSorted(arr, n);
    return 0;
}