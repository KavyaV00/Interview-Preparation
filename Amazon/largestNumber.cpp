/*
    Find largest number that can be formed from a given array of numbers.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

class Solution {
    public:
        static bool compareNum(string a, string b) {
            
            return a + b > b + a;
        }

        string largestNumber(const vector<int> &num) {
            string result;
            vector<string> str;
            for (int i = 0; i < num.size(); i++) {
                str.push_back(to_string(num[i]));
            }
            // cout<< num[0]+num[1] << "\t" << num[1]+num[0] << endl;
            sort(str.begin(), str.end(), compareNum);
            for (int i = 0; i < str.size(); i++) {
                result += str[i];
            }

            int pos = 0;
            while (result[pos] == '0' && pos + 1 < result.size()) pos++; 
            return result.substr(pos);
        }
};