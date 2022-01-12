/*
    Find 2 numbers in a sorted array such that they add up to a given sum
*/

#include <iostream>
using namespace std;

int main() {
    int i, n;
    cin>> n;
    int arr[n];
    for(i=0; i<n; i++) 
        cin>> arr[i];
    cout<< endl;
    int ptr1 = 0, ptr2 = n-1, sum, currSum, flag = 0;
    cin>> sum;
    while(ptr1<ptr2) {
        currSum = arr[ptr1] + arr[ptr2];
        if(currSum < sum)
            ptr1++;
        else if(currSum > sum)
            ptr2--;
        else {
            cout<< arr[ptr1] << "+" << arr[ptr2] << "=" << sum;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        cout<< "No such elements";
}
