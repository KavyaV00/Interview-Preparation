#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

int main() {
    int maxNo = INT_MIN;
    int minNo = INT_MAX;
    int i, n;
    cout<< "Enter n: ";
    cin>> n;
    int arr[n];
    cout << "Enter n elements: ";
    for(i=0; i<n; i++)
        cin>> arr[i];
    
    for(i=0; i<n; i++) {
        maxNo = max(maxNo, arr[i]);
        minNo = min(minNo, arr[i]);
    }
    cout<< "Greatest element is: " << maxNo << endl;
    cout<< "Least number is: " << minNo;
    return 0 ;
 }
