#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubset(vector<int> v, vector<vector<int>> res) {
    sort(v.begin(),v.end());
    vector<int> temp;
    int l=res.size(),j,i,start, end=0;
    res.push_back({});
    for(i=0;i<v.size();i++) {
        start=0;
        if(i>0 && v[i]==v[i-1]) {
            start=end+1;
        }
        
        int n = res.size();
        
        end=n-1;
        for(j=start; j<n;j++) {
            temp=res[j];
            temp.push_back(v[i]);
            res.push_back(temp);
        }
    }
    for(auto i: res) {
        for(auto j: i) {
            cout<<j;
        }
        cout<< endl;
    }
}

int main() {
    vector<int> v= {1,2,2};
    vector<vector<int>> res={};
    findSubset(v,res);
    return 0;
}