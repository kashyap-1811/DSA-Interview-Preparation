// leet - 300
// https://leetcode.com/problems/longest-increasing-subsequence/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> sorted(s.begin(), s.end());

        int n1 = nums.size();
        int n2 = sorted.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(nums[i-1] == sorted[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n1][n2];
    }
};