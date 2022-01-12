/*
    Given two strings, write a method to decide if one is permutation of the other

    check for equal length - frequency of occurance of each char must be same
*/

#include <iostream>
#include <unordered_map>
using namespace std;

bool isPermutation(string s1, string s2) {
    unordered_map<char, int> frequency; // Automatically initialized to 0

    if(s1.length() != s2.length())
        return false;
    for(int i=0; i<s1.length(); i++) {
        frequency[s1[i]]++;
    }
    for(int i=0; i<s2.length(); i++) {
        frequency[s2[i]]--;
    }
    unordered_map<char, int>::iterator itr;
    for(itr = frequency.begin(); itr!=frequency.end(); itr++) {
        if(itr->second!=0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1, s2;
    cin>> s1 >> s2;
    cout<< isPermutation(s1, s2) << endl;
    return 0;
}
