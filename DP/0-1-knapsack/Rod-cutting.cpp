// http://geeksforgeeks.org/problems/rod-cutting0840/1
 
#include <bits/stdc++.h>
using namespace std;
 
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dp;
    
    int memo(int i, int curr, vector<int> &price, int &totalLength){
        if(i == -1)
            return 0;
        if(dp[i][curr] != -1)
            return dp[i][curr];
        
        int notTake = memo(i - 1, curr, price, totalLength);
        
        int take = 0;
        if(i + 1 + curr <= totalLength)
            take = price[i] + memo(i, curr + i + 1, price, totalLength);
        
        return dp[i][curr] = max(notTake, take);
    }
    
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        dp = vector<vector<int>>(n, vector<int>(n + 1, -1));
        
        // memoization
        // return memo(n-1, 0, price, n);
        
        // tabulation
        // Base case: when only length 1 rods are available
        for (int len = 1; len <= n; len++)
            dp[0][len] = len * price[0];  // we can only cut 1-length pieces
        
        // Build the DP table
        for (int i = 1; i < n; i++) {
            int rodLength = i + 1;  // since price[i] is for rod of length (i+1)
            for (int len = 0; len <= n; len++) {
                int notTake = dp[i - 1][len];
                int take = 0;
                if (rodLength <= len)
                    take = price[i] + dp[i][len - rodLength]; // unbounded — stay on i

                dp[i][len] = max(take, notTake);
            }
        }
        
        return dp[n-1][n];
    }
};