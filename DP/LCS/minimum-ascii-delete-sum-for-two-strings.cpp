// leet - 712
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        // dp[i][j] = maximum ASCII sum of common subsequence of s1[i:] and s2[j:]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // build dp table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    dp[i][j] = s1[i] + dp[i + 1][j + 1]; // keep this char
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]); // skip one
            }
        }

        // total ASCII sums
        int total1 = accumulate(s1.begin(), s1.end(), 0);
        int total2 = accumulate(s2.begin(), s2.end(), 0);

        // (sum1 + sum2) - 2 * (max ASCII sum of common subsequence)
        return (total1 + total2) - 2 * dp[0][0];
    }
};