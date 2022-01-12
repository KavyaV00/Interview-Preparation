/*
    Given a 2D matrix, sorted ascending row wise and sorted descending column-wise.
    Search an element present in the matrix.
*/

#include <iostream>
using namespace std;

int main() {
    int i, j, m, n, num, flag = 0, row = 0, col = 0, curr;
    cin>> m >> n;
    int arr[m][n];
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            cin>> arr[i][j];
    cin>> num;
    while(row<m && col<n) {
        curr = arr[row][col] ;
        if(curr == num) {
            flag = 1;
            cout<< "Found at arr[" << row << "][" << col << "]\n";
            break;
        }
        else if(curr < num) 
            row++;
        else 
            col--;

    }
    if(flag == 0) 
        cout<< "Number not found";
    return 0;
}
