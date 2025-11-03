// leet - 474
// https://leetcode.com/problems/ones-and-zeroes/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int memo(int i, int zeros, int ones, vector<vector<int>> &s, int& m, int &n, 
            vector<vector<vector<int>>> &dp){
        if(i == s.size())
            return 0;
        if(dp[i][zeros][ones] != -1)
            return dp[i][zeros][ones];
        
        // not take
        int notTake = memo(i+1, zeros, ones, s, m, n, dp);

        // take
        int take = 0;
        if(zeros + s[i][0] <= m && ones + s[i][1] <= n)
            take = memo(i+1, zeros + s[i][0], ones + s[i][1], s, m, n, dp) + 1;

        return dp[i][zeros][ones] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> s(strs.size(), vector<int>(2, 0));

        for(int i=0; i<strs.size(); i++){
            for(char &c : strs[i]){
                if(c == '1')
                    s[i][1]++;
                else
                    s[i][0]++;
            }
        }

        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return memo(0, 0, 0, s, m, n, dp);
    }
};