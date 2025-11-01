// leet - 213
// https://leetcode.com/problems/house-robber-ii/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int memo(int i, int n, vector<int>& nums, vector<int>& dp){
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];

        return dp[i] = max(nums[i] + memo(i+2, n, nums, dp), memo(i+1, n, nums, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        vector<int> dp1(n+1, -1), dp2(n+1, -1);
        return max(memo(0, n-1, nums, dp1), memo(1, n, nums, dp2));
    }
};