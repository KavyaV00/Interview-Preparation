/*
    Find first and last occurance of an element in an array using recursion.
*/

#include <iostream>
using namespace std;

void lastOcc(int arr[], int n, int i, int num) {
    if(i==0) 
        return;
    if(arr[i] == num) {
        cout<< "Last present at " << i;
        return;
    }
    else {
        lastOcc(arr, n, i-1, num);
    }
}

void firstOcc(int arr[], int n, int i, int num) {
    if(i==n) {
        cout<< "Not present";
        return;
    }
    if(arr[i] == num) {
        cout<< "First present at " << i << endl;
        lastOcc(arr, n, n, num);
    }
    else {
        firstOcc(arr, n, i+1, num);
    }
}

int main() {
    int n, i, num;
    cin>> n;
    int arr[n];
    for(i=0; i<n; i++)
        cin>> arr[i];
    cin>> num;
    firstOcc(arr, n, 0, num);
}