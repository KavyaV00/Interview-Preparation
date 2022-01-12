#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int bestSum(int targetSum, vector<int> numbers, unordered_map<int, int> m) {
    if(m.find(targetSum) != m.end())
        return m[targetSum];

    if(targetSum == 0)
        return true;

    for(auto i : numbers) {
        int remainder = targetSum - i;
        int result 
    }

}


int main() {



    return 0;
}
