/*
    A day is considered record breaking if :
    ● The number of visitors on the day is strictly larger than the number of
    visitors on each of the previous days.
    ● Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
    
    Note that the very first day could be a record breaking day!
*/

#include <iostream>
using namespace std;

int main() {
    int n, i;
    cin >> n;
    int arr[n];
    for(i=0; i<n; i++) 
        cin>> arr[i];
    int max_global = 0, max_curent = 0, count = 0;
    for(i=0; i<n ; i++) {
        if(arr[i]>max_global) {
            if(i+1==n || arr[i] > arr[i+1]) {
                count++;
                max_global = arr[i];
                // cout << "i:  " << i <<endl;
            }
        }
        else    
            continue;
    }
    cout<< count << endl;
}
