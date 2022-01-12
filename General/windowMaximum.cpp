/*
    You are given an array, and a value k. Find the maximum of each window of k elements in the array.
*/

#include <iostream>
using namespace std;

int main() {
    int max_element = INT16_MIN, i, n, k;
    cin>> n;
    int arr[n];
    for(i=0; i<n; i++)
        cin>> arr[i];
    cin>> k;
    int c = 0;
    int ptr1=0, ptr2=0;
    while(ptr1<=n-k) {
        max_element = max(max_element, arr[ptr2]);
        c++;
        ptr2++;
        
        // cout<< max_element << "***" << endl;
        if(c == k) {
            ptr1++;
            ptr2 = ptr1;
            c = 0;
            cout << max_element << " " << endl;
        }
    }
    return 0;
}
