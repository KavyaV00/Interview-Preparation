/* 

    WAP that, given an array A[] of n numbers and another number x, 
    determines whether or not there exist two elements in A whose sum is exactly x.

    A = {2, 3, 6, 7, 9, 10}
    x = 15
    brute force - traverse, find if x - A[i] present
    2 pointer approach - if A[] is sorted
    hash table - store complements in the array as each element is visited- each element is checked whether present in hash table

*/

#include <iostream>
#include <unordered_set>
using namespace std;

bool checkPair(int* arr, int n, int x) {
    unordered_set<int> complements;
    for(int i=0; i<n; i++) {
        if(complements.count(arr[i]) != 0)
            return true;
        complements.insert(x-arr[i]);
    }
    return false;
}

int main() {

    int n;
    cin>> n;
     
     int *arr =  new int [n];
     for(int i=0; i<n;i++) {
         cin>> arr[i];
     }

     int x;
     cin>>x;
     if(checkPair(arr, n, x)) {
         cout<< "Pair exists" <<endl;
     }
     else {
         cout<< "Pair doesnt exist" << endl;
     }
    return 0;
}
