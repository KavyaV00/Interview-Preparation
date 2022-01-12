#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[10][10];
int t[10][10];


int lcsTopDown(string x, string y, int n, int m) {
    int i, j;
    for(i=0;i<=n;i++) {
        for(j=0; j<=m; j++) {
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }
    cout<<"hello";
    int max_l=0;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(x[i-1]==y[j-1]) 
                t[i][j]=1+t[i-1][j-1];
            else
                t[i][j]=0;
            max_l=max(max_l, t[i][j]);
            cout<< i<< " "<< j << endl;
        }
    }
    return max_l;
}

int main() {
    string x="abcdfg";
    string y="axbcegh";
    memset(dp, -1, sizeof(dp));
    cout<< lcsTopDown(x,y,x.length(), y.length());
    return 0;
}