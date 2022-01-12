#include <iostream>
#include <string>
using namespace std;

void permutate(string processed, string unprocessed) {
    if(unprocessed=="") {
        cout<< processed <<endl;
        return;
    }
    char ch=unprocessed[0];
    int n=processed.length();
    for(int i=0;i<=n;i++) {
        string first = processed.substr(0,i);
        string last = processed.substr(i,n);
        permutate(first+ch+last, unprocessed.substr(1));
    }
}

int main() {
    string s="abc";
    permutate("",s);
    return 0;
}