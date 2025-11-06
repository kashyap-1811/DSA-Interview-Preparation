// leet - 44
// https://leetcode.com/problems/wildcard-matching/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool memo(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i == s.size() && j == p.size()) return true;
        if (j == p.size()) return false;

        if (dp[i][j] != -1) return dp[i][j];

        if (i < s.size() && (s[i] == p[j] || p[j] == '?')) {
            return dp[i][j] = memo(i + 1, j + 1, s, p, dp);
        }

        if (p[j] == '*') {
            // Option 1: skip '*'
            if (memo(i, j + 1, s, p, dp))
                return dp[i][j] = true;
                
            // Option 2: match current char with '*'
            if (i < s.size() && memo(i + 1, j, s, p, dp))
                return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return memo(0, 0, s, p, dp);
    }
};
