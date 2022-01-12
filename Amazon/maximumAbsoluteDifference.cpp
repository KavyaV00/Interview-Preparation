// Q. You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.
// f(i, j) = |A[i] - A[j]| + |i - j|
// Link

// Solution:
// Intuition : Try to separate the terms of i and j. Separate them using neg sign because then the first one will act as max and second will act a min. Hence will give the max abs diff.
// Four cases:

// A[i] > A[j] , i > j => f(i, j) = (A[i] - A[j]) + (i-j) = (A[i]+i) - (A[j]+j)
// A[i] < A[j] , i < j => f(i, j) = -(A[i] - A[j]) + -(i-j) = -(A[i]+i) + (A[j]+j) = - ( (A[i]+i) - (A[j]+j) )
// A[i] > A[j] , i < j => f(i, j) = (A[i] - A[j]) + -(i-j) = (A[i]-i) - (A[j]-j)
// A[i] < A[j] , i > j => f(i, j) = -(A[i] - A[j]) + (i-j) = -(A[i]-i) + (A[j]-j) = - ( (A[i]-i) - (A[j]-j) )
// We can see that 1 and 2 will give the same ans, 3 and 4 will also give the same ans.
// So we will find max and min for them. The maximum diff bn them will give the ans.

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;
int maxArr(vector<int> &nums) {
    int mx1 = INT_MIN, mn1 = INT_MAX, mx2 = INT_MIN, mn2 = INT_MAX;
    for(int i = 0; i < nums.size(); ++i){
        // for eq 1
        mx1 = max(mx1, nums[i]+i);
        mn1 = min(mn1, nums[i]+i);
        
        // for eq2
        mx2 = max(mx2, nums[i]-i);
        mn2 = min(mn2, nums[i]-i);
    }
    int ans1 = mx1 - mn1;
    int ans2 = mx2 - mn2;
    return max(ans1, ans2);
    
}