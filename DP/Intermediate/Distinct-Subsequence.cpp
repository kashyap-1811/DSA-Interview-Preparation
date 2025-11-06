// leet - 115
// https://leetcode.com/problems/distinct-subsequences/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int memo(int i, int j, int& n, int& m, string& s, string& t, vector<vector<int>>& dp){
        if(j == m)
            return 1;
        if(i == n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 0;

        if(s[i] == t[j])
            dp[i][j] = memo(i+1, j+1, n, m, s, t, dp);
        
        return dp[i][j] += memo(i+1, j, n, m, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memo(0, 0, n, m, s, t, dp);
    }
};