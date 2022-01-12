#include <iostream>
#include <vector>
#include <map>
using namespace std;


int dfs(int i, bool even, vector<int> v, map<pair<int,int>, int> &dp) {
        if(i==v.size())
            return 0;
        if(dp.find({i,even})!= dp.end()) 
            return dp[{i,even}];
        int current;
        if(even)
            current=v[i];
        else    
            current=-1*v[i];
        dp[{i,even}]=max(current+dfs(i+1, !even,v,dp), dfs(i+1, even,v,dp));
        return dp[{i,even}];
    }

void findSeq(vector<int> v) {
    map<pair<int, int>, int> dp;

    
    cout<< dfs(0, true,v,dp);
}

int main() {
    vector<int> v={4,2,5,3};
    findSeq(v);
    return 0;
}