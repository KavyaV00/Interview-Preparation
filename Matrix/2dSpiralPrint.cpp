/*
    Print the given 2d array in spiral order
*/

#include <iostream>
using namespace std;

int main() {
    int n, m, i, j;
    cin>> m >> n;
    int arr[m][n];
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++)
            cin>> arr[i][j];
    }
    int row_start = 0, row_end = m-1, col_start = 0, col_end = n-1, row, col;
    while(row_start<=row_end && col_start<=col_end) {
        for(col=col_start; col<=col_end; col++)
            cout<< arr[row_start][col] << " ";
        row_start++;
        for(row=row_start; row<=row_end; row++) 
            cout<< arr[row][col_end] << " ";
        col_end--;
        for(col=col_end; col>=col_start; col--)
            cout<< arr[row_end][col] << " ";
        row_end--;
        for(row=row_end; row>=row_start; row--) 
            cout<< arr[row][col_start] << " ";
        col_start++;
    }
    return 0;
}
