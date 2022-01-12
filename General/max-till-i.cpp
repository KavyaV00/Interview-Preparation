#include <iostream>
#include <climits>
#include <math.h>
using namespace std;


int main() {
    int n, i;
    int maxNo = INT_MIN;
    cin>> n;
    int arr[n];
    for(i=0; i<n; i++)
        cin>> arr[i];

    for(i=0; i<n; i++) {
        maxNo = max(arr[i], maxNo);
        cout<< maxNo << " ";
    }
    return 0;
}
