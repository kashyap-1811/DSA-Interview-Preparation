// leet - 2707
// https://leetcode.com/problems/extra-characters-in-a-string/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> dp;

    int memo(int i, string s, vector<string> &dictionary) {
        if(i == s.size())
            return 0;
        if(dp[i] != INT_MAX)
            return dp[i];

        // skip
        int skip = 1 + memo(i+1, s, dictionary);

        // take if possible
        int take = INT_MAX;
        for(auto d : dictionary) {
            if(d.size() > s.size() - i)
                continue;
            string substr = s.substr(i, d.size());
            if(substr == d)
                take = min(take, memo(i+d.size(), s, dictionary));
        }

        return dp[i] = min(skip, take);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        dp = vector<int>(n + 1, INT_MAX);
        // return memo(0, s, dictionary);

        dp[0] = 0;

        for(int i=1; i<=n; i++) {
            dp[i] = 1 + dp[i-1];
            for(auto d : dictionary) {
                int start = i - d.size();
                if(start >= 0 && s.substr(start, d.size()) == d)
                    dp[i] = min(dp[i], dp[start]);
            }
        }

        return dp[n];
    }
};