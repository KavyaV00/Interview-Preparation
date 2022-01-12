/*
    Given an unsorted array A of size N of non-negative integers, find a continuous subarray which adds to a given number S.

    Bruteforce - Generate all possible subarray sums to find a match

    Ideal - Use 2 pointers. Move the second one as long as the sum 
    is a value below the S. If greater then increment the first pointer 
    till u get a sum lesser than S, at the same time subtracting the value 
    of sum by corresponding element value. 
    This is continued till required S is obtained.
*/

#include <iostream>
using namespace std;

int main() {
    int i = 0, n, sum, j = 0;
    cin>> n;
    int arr[n];
    for(i=0; i<n; i++)
        cin>> arr[i];
    cin>> sum;
    int st, end, currSum, flag = 0;
    i = 0;
    while(j < n) {
        while(j < n && currSum < sum) {
            // cout<< currSum << "," << j << endl << "**"; 
            currSum+=arr[j];
            j++;
        }
        if(currSum == sum) {
            st = i; end = j-1;
            break;
        }
        while(currSum > sum) {
            currSum -= arr[i];
            i++;
        }
    }
    cout<< st << ":" << end;
}
