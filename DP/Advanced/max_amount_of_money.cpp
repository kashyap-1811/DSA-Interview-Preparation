// leet - 3418
// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        int k = 3;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, INT_MIN)));

        // Base case
        dp[0][0][0] = coins[0][0];

        for (int w = 1; w < k; w++)
            dp[0][0][w] = max(coins[0][0], 0); // optional skip

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                for (int w = 0; w < k; w++) {

                    // From top
                    if (i > 0) {
                        // take coin
                        if (dp[i - 1][j][w] != INT_MIN)
                            dp[i][j][w] =
                                max(dp[i][j][w], dp[i - 1][j][w] + coins[i][j]);

                        // skip coin
                        if (w > 0 && dp[i - 1][j][w - 1] != INT_MIN)
                            dp[i][j][w] = max(dp[i][j][w], dp[i - 1][j][w - 1]);
                    }

                    // From left
                    if (j > 0) {
                        // take coin
                        if (dp[i][j - 1][w] != INT_MIN)
                            dp[i][j][w] =
                                max(dp[i][j][w], dp[i][j - 1][w] + coins[i][j]);

                        // skip coin
                        if (w > 0 && dp[i][j - 1][w - 1] != INT_MIN)
                            dp[i][j][w] = max(dp[i][j][w], dp[i][j - 1][w - 1]);
                    }
                }
            }
        }

        return *max_element(dp[m - 1][n - 1].begin(), dp[m - 1][n - 1].end());
    }
};