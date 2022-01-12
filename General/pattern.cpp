// Pattern 1 - Hollow Rectangle

// *****
// *   *
// *   *
// *   *
// *****

#include <iostream>
using namespace std;

// void pattern1(int m, int n) {
//     for(int i=0; i<m; i++) {
//         for(int j=0; j<n; j++) {
//             if(i==0 || j==0 || i==m-1 || j==n-1) 
//                 cout<< "*";
//             else    
//                 cout<< " ";
//         }
//         cout<< endl;
//     }
// }

// *****
// ****
// ***
// **
// *

void pattern2(int m, int n) {
    for(int i=m; i>0; i--) {
        for(int j=0; j<i; j++) 
            cout<< "#";
        cout<< endl;
    }
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, i, j;
    // cout<<"ENter: ";
    cin>> m >> n; 

    for(i=0; i<m; i++) {
        for(j=0; j<m; j++) {
            if(i+j > (n/2))
                cout <<"*";
            else    
                cout<< " ";
        }
        cout<< endl;
    }
}



