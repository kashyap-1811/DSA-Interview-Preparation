// leet - 459
// https://leetcode.com/problems/repeated-substring-pattern/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string sub = doubled.substr(1, doubled.size() - 2);
        return sub.find(s) != string::npos;
    }
};