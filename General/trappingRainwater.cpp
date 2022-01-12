#include <iostream>
using namespace std;

void maxwater1(int arr[], int n) {
    int i, left, right, maxLeft = 0, maxRight = 0, qty = 0, j;
    for(i=1; i<n; i++) {
        left = arr[i], right = arr[i];
        for(j=0; j<i; j++)
            maxLeft = max(maxLeft, arr[j]);
        for(j=i+1; j<n; j++)
            maxRight = max(maxRight, arr[j]);
        qty += (min(maxLeft, maxRight)) - arr[i]; 
    }
    cout<< qty;
}

void maxwater2(int arr[], int n) {
    int left[n], right[n], maxLeft = 0, maxRight = 0, qty = 0;
    for(i=0; i<n; i++)
        maxLeft = max(maxLeft, arr[i]);
    for(i=n-1; i>=0; i--)
        maxRight = max(maxRight, arr[i]);
    for(i=0; i< n; i++) {
        qty += min(left[i], right[i]) - arr[i];
    }
    cout<< qty;
}

int main() {
    int n, i, left, right, maxLeft = 0, maxRight = 0, qty = 0, j;
    int n = 12;
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    maxwater1(arr, n);
    maxwater2(arr,n);
    
    return 0;
}
