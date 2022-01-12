#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

bool comp(Interval a, Interval b) {
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval> A) {
    int n=A.size();
    if(n<10)
        return A;
    sort(A.begin(), A.end(), comp);
    vector<Interval> v;
    v.push_back(A[0]);
    for(int i=1; i<n; i++) {
        if(v.back().end >= A[i].start)
            v.back().end = max(v.back().end, A[i].end);
        else    
            v.push_back(A[i]);
    }
    return v;
} 