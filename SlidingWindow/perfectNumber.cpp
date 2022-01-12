/*
    Given an array and an integer K. Find the subarray of length K which has the maximum number of perfect squares.
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPerfect(int n) {
    int i, sum = 1;
    for(i=2; i<sqrt(n); i++) {
        if(n % i == 0) {
            if(i*i == n)
                sum += i;
            else 
                sum += i + n/i;
        }
    }
    if(sum == n)
        return true;
    return false;
}

int findMaxSubArray(vector<int> v, int k) {
    int count = 0, i;
    for(i=0; i<k; i++) {
        if(isPerfect(v[i])) {
            count++;
            v[i] = 1;
        }
        else    
            v[i] = 0;       
    }
    int res = count, pos = 0;
    for(i=k; i<v.size(); i++) {
        count -= v[i-k];
        if(isPerfect(v[i])){
            v[i] = 1;
            count++;
        }
        else    
            v[i] = 0;
        if(count > res) {
            res = count;
        }
    }
    return res;
}

int main() {
    vector<int> v = {1,2,3,6};
    int k = 2;
    int i, res = findMaxSubArray(v, k);
    cout<< res;
    return 0;
}