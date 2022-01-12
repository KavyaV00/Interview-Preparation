#include <iostream>
#include <vector>
using namespace std;

void findSubset(vector<int> v, vector<vector<int>> res) {
    vector<int> temp;
    int l=res.size(),j;
    res.push_back({});
    for(auto i: v) {
        int n = res.size();
        for(j=0; j<n;j++) {
            temp=res[j];
            temp.push_back(i);
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
    vector<int> v= {1,2,3};
    vector<vector<int>> res={};
    findSubset(v,res);
    return 0;
}