/*
    Generate all subsequences of a string recursively.
*/

#include <iostream>
#include <string>
using namespace std;

void subsequence(string s, string ans) {
    
    if(s.length() == 0) {
        cout<< ans << endl;
        return;
    }

    char ch = s[0];
    string remaining = s.substr(1);
    subsequence(remaining, ans);
    subsequence(remaining, ans+ch);

}

int main() {
    string s;
    cin>> s;
    subsequence(s, "");
    return 0;

}