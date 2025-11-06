// leet - 516
// https://leetcode.com/problems/longest-palindromic-subsequence/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][n];
    }
};