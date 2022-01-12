/*
    Take transpose, flip horizontally.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int i, j, m=a.size(), n=a.size(),temp;
        for(i=0;i<m;i++) {
            for(j=i;j<n;j++) {
                temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        }
        for(i=0;i<m;i++) {
            for(j=0;j<n/2;j++) {
                temp=a[i][j];
                a[i][j]=a[i][n-1-j];
                a[i][n-1-j]=temp;
            }
        }
    }
};
