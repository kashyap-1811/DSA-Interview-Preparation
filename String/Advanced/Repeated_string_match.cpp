// leet - 686
// https://leetcode.com/problems/repeated-string-match/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int k = 1;
        string q = a;

        while(q.size() < b.size()){
            q += a;
            k++;
        }

        if(q.find(b) != string::npos)
            return k;
        if((q+a).find(b) != string::npos)
            return k+1;
        return -1;
    }
};