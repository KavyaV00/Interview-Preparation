#include <iostream>
#include <string>
using namespace std;

void letterCombo(string p, string up) {
    if(up=="") {
        cout<< p<< endl;
        return;
    }
    int ch=up[0]-48;
    // cout<< ch << "\t" << char('a'+ch);
    int start=(int(ch)-2)*3;
    if(start>=7)
        start+=1;
    int end=start+3;
    if(int(ch)==9 || int(ch)==7)
        end+=1;
    for(int index=start;index<end;index++) {
        char c=char('a'+index);
        letterCombo(p+c,up.substr(1));
    }


}

int main() {
    string s="23";
    letterCombo("",s);
}