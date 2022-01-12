/*
    The span of the stock's price today is defined as the maximum no:of consecutive days(starting from today and going backwards) for which 
    the price of the stocks was less than or equal to today's price. 
    Find span of the stocks for all the days.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void span1(int arr[], int n) {
    int i, days = 0, j;
    for(i=0; i<n; i++) {
        days = 0;
        for(j=i; j>=0; j--) {
            if(arr[j] <= arr[i])
                days++;
            else break;
        }
        cout<< days << endl;
    }
}

void span2(vector<int> arr, int n) {
    stack<pair<int,int>> st;
    int i, days = 0;
    vector<int> ans;
    for(auto price : arr) {
        int days = 1;
        while(!st.empty() && st.top().first <= price) {
            days += st.top().second;
            st.pop();
        }
        st.push({price, days});
        ans.push_back(days);
    }
}

int main() {
    // int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int arr[] = {10,20,40,30,50};
    span1(arr, 5);

}
