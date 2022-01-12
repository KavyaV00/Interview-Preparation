/*
    Sort the array such that
    a[0]>=a[1]<=a[2]>=a[3]....
*/

#include <iostream>
#include <vector>
using namespace std;

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void waveSort(int v[],int n) {
    int i;
    for(i=1; i<n-1; i+=2) {
        if(v[i]>v[i-1])
            swap(v, i, i-1);
        if(i!=n-1 && v[i]>v[i+1]) 
            swap(v, i, i+1);
    }
}

int main() {
    int a[] = {1,3,4,7,5,6,2};
    int n=7;
    waveSort(a,n);
    for(int i=0;i<n;i++)
        cout<< a[i] << "\t";
}
