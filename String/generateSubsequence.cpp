#include <iostream>
#include <string>
using namespace std;

void permutate(string processed, string unprocessed) {
    if(unprocessed=="") {
        cout<< processed <<endl;
        return;
    }
    permutate(processed+unprocessed[0], unprocessed.substr(1));
    permutate(processed, unprocessed.substr(1));
}

int main() {
    string s="abc";
    permutate("",s);
    return 0;
}