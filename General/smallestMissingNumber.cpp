/*
    Find the smallest positive missing number in the given array.
        Given : 10^-6 < arr[i] < 10^6

    Approach - Use a boolean check array, initialized with False. 
    Traverse through input array. When a positive number 'i' is encountered in the array, change the value of
    check[i] as T. 
    Iterate through the check array and print the index of the first False.
*/

#include <iostream>
using namespace std;

int main() {
    int n, i;
    cin>> n;
    int arr[n];

    for(i=0; i<n; i++) 
        cin>> arr[i];

    const int N = 1e6 + 2; // To store all the numbers
    bool check[N];

    for(i=0; i<N; i++) {
        check[i] = false;
    }
    for(i=0; i<n; i++) {
        if(arr[i] > 0) {
            check[arr[i]] = true; 
        }
    }
    
    i = 1;
    while(check[i]==true)
        i++;
    cout<< i;
    return 0;
}
