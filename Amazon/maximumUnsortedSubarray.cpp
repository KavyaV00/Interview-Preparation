
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;

vector<int> subUnsort(vector<int> &arr) {
    
    int n=arr.size();
    int s = 0, e = n-1, i, max, min;
 
// step 1(a) of above algo
for (s = 0; s < n-1; s++)
{
    if (arr[s] > arr[s+1])
    break;
}
vector<int> res;
if (s == n-1)
{
    res.push_back(-1);
    return res;
}
 
// step 1(b) of above algo
for(e = n - 1; e > 0; e--)
{
    if(arr[e] < arr[e-1])
    break;
}
 
// step 2(a) of above algo
max = arr[s]; min = arr[s];
for(i = s + 1; i <= e; i++)
{
    if(arr[i] > max)
    max = arr[i];
    if(arr[i] < min)
    min = arr[i];
}
 
// step 2(b) of above algo
for( i = 0; i < s; i++)
{
    if(arr[i] > min)
    {
    s = i;
    break;
    }    
}
 
// step 2(c) of above algo
for( i = n -1; i >= e+1; i--)
{
    if(arr[i] < max)
    {
    e = i;
    break;
    }
}
    res.push_back(s);
    res.push_back(e);
    return res;
}
