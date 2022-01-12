#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[10][10];
int t[10][10];

int lcs(string x, string y, int n, int m) {
    if(n==0 || m==0) {
        return 0;
    }
    if(dp[n][m]!=-1)
        return dp[n][m];

    if(x[n-1]==y[m-1]) {
        dp[n][m]=1+lcs(x,y,n-1,m-1);
        return dp[n][m];
    }
    else {
        dp[n][m]=max(lcs(x,y,n,m-1), lcs(x,y,n-1,m));
        return dp[n][m];
    }
}

int lcsTopDown(string x, string y, int n, int m) {
    int i, j;
    for(i=0;i<=n;i++) {
        for(j=0; j<=m; j++) {
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }
    cout<<"hello";
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(x[i-1]==y[j-1]) 
                t[i][j]=1+t[i-1][j-1];
            else    
                t[i][j]=max(t[i][j-1], t[i-1][j]);
            cout<< i<< " "<< j << endl;
        }
    }
    return t[n][m];
}

int main() {
    string x="abcdfg";
    string y="axbcegh";
    memset(dp, -1, sizeof(dp));
    cout<< lcsTopDown(x,y,x.length(), y.length());
    return 0;
}