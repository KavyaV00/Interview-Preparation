#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[10][10];
int t[10][10];

void lcsTopDown(string x, string y, int n, int m) {
    int i, j;
    for(i=0;i<=n;i++) {
        for(j=0; j<=m; j++) {
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(x[i-1]==y[j-1]) 
                t[i][j]=1+t[i-1][j-1];
            else    
                t[i][j]=max(t[i][j-1], t[i-1][j]);
            
        }
    }
    i=n,j=m;
    stack<char> st;
    while(i>0 || j>0) {
        cout<< i<< " "<< j << endl;
        if(x[i-1]==y[j-1]) {
            st.push(x[i-1]);
            i--;j--;
        }
        else {
            if(t[i-1][j]>t[i][j-1]) {
                st.push(x[i-1]);
                i--;
            }
            else {
                st.push(y[j-1]);
                j--;
            }
        }
    }
    while(i>0) {
        st.push(x[i-1]);
        i--;
    }
    while(j>0) {
        st.push(y[j-1]);
        j--;
    }
    while(!st.empty()) {
        char ch=st.top();
        st.pop();
        cout<<ch;
    }
}



int main() {
    string x="abcdfg";
    string y="axbcegh";
    memset(dp, -1, sizeof(dp));
    lcsTopDown(x,y,x.length(), y.length());
    return 0;
}