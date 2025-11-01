// leet - 91
// https://leetcode.com/problems/decode-ways/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0') return 0;

        vector<int> dp(n + 1, 0);
        dp[n] = 1; // base case: empty string has 1 way

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0; // cannot start with '0'
            } else {
                // one-step decode
                dp[i] = dp[i + 1];

                // two-step decode (if valid)
                if (i + 1 < n) {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (num >= 10 && num <= 26)
                        dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};