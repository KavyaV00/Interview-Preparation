#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int solve(vector<int> v, int i, vector<int> &dp) {
    // cout<< i<< endl;
    if(i>v.size())
        return 0;
    // cout<< i<< endl;
    if(i==v.size())
        return 0;
    // cout<< i<< endl;
    int curr=v[i];
    // cout<< curr<< endl;
    if(dp[i] != -1)
        return dp[i];
    // cout<< i<< endl;
    
    dp[i] = max(v[i]+solve(v,i+2,dp), solve(v,i+1,dp));
    return dp[i];    
}

int main() {
    vector<int> v = {1,2,3,1};
    vector<int> dp(4);
    dp.assign(dp.size(), -1);
    cout<< "hello";
    cout<< solve(v,0,dp);

    return 0;
}