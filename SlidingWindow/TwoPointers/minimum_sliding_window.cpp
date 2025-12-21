// leet - 76
// https://leetcode.com/problems/minimum-window-substring/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool check(unordered_map<char, int> &T, unordered_map<char, int> &freq){
        int count = 0;
        for(auto &p : T){
            if(freq[p.first] < p.second)
                break;
            count++;
        }
        
        return count == T.size();
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> T;
        unordered_map<char, int> freq;

        for(char &c : t)
            T[c]++;
        
        int l = 0, r = 0;
        string ans = "";
        int startIdx = -1;
        int minLen = INT_MAX;

        while(r < s.size()){
            freq[s[r]]++;            
            
            while(check(T, freq)){
                if(minLen > (r - l + 1)){
                    minLen = r - l + 1;
                    startIdx = l;
                }
                freq[s[l]]--;
                l++;
            }

            r++;
        }

        if(startIdx != -1)
            ans = s.substr(startIdx, minLen);
        return ans;
    }
};