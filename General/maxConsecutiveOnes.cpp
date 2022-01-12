/*
    Goven an array A of 0s and 1s, we may change up to K values from 0 to 1. Return the length of the longest(contiguous) subarray that contains only 1s.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1 = {1,1,1,0,0,0,1,1,1,1,0},
    v2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1
    };
    int k1 = 2, k2 = 3;
    int zeroCount = 0;
    int i = 0, j, ans = 0;
    for(j=0; j<v1.size(); j++) {
        if(v1[j] == 0)
            zeroCount++;
        while(zeroCount > k1) {
            if(v1[i] == 0)
                zeroCount--;
            i++;
        }
        ans = max(ans, j-i+1);
    }
    cout<< ans;
    return 0; 
}
