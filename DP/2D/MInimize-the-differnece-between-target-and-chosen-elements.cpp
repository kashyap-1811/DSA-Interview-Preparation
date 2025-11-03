// leet - 1981
// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        const int MAX_SUM = 5000; // sum limit to avoid overflow
        vector<bool> dp(MAX_SUM + 1, false);
        dp[0] = true;

        for (auto &row : mat) {
            vector<bool> next(MAX_SUM + 1, false);
            for (int sum = 0; sum <= MAX_SUM; sum++) {
                if (!dp[sum]) continue;
                for (int val : row) {
                    if (sum + val <= MAX_SUM)
                        next[sum + val] = true;
                }
            }
            dp = next;
        }

        int ans = INT_MAX;
        for (int sum = 0; sum <= MAX_SUM; sum++) {
            if (dp[sum])
                ans = min(ans, abs(sum - target));
        }
        return ans;
    }
};