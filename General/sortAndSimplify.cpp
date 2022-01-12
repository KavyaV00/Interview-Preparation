/*
    Change the elements in the array to represent their sorted order - from 0 to n-1.

    Approach: Use a pair - (value, index_of_original_array).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(pair<int,int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
} 


int main() {
    int n, i;
    cin>> n;
    int arr[n];
    for(i=0; i<n; i++)
        cin>> arr[i];
    vector <pair <int, int>> v;
    for(i=0; i<n; i++) {
        v.push_back(make_pair(arr[i], i));
    }
    sort(v.begin(), v.end(), myCompare);
    for(i=0; i<n; i++) {
        arr[v[i].second] = i;
    }
    for(i=0; i<n; i++) 
        cout<< arr[i] << " ";
}
