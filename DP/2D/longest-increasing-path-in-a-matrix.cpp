// leet - 329
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int& m, int& n){
        if(dp[i][j] == -1)
            return 0;

        if(dp[i][j] != -2)
            return dp[i][j];

        dp[i][j] = -1;
        int maxLen = 0;

        //up
        if(i-1>=0 && dp[i-1][j]!=-1 && matrix[i-1][j]>matrix[i][j])
            maxLen = max(maxLen, memo(i-1, j, matrix, dp, m, n)+1);

        //down
        if(i+1<m && dp[i+1][j]!=-1 && matrix[i+1][j]>matrix[i][j])
            maxLen = max(maxLen, memo(i+1, j, matrix, dp, m, n)+1);

        //left
        if(j-1>=0 && dp[i][j-1]!=-1 && matrix[i][j-1]>matrix[i][j])
            maxLen = max(maxLen, memo(i, j-1, matrix, dp, m, n)+1);

        //right
        if(j+1<n && dp[i][j+1]!=-1 && matrix[i][j+1]>matrix[i][j])
            maxLen = max(maxLen, memo(i, j+1, matrix, dp, m, n)+1);

        return dp[i][j] = maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<tuple<int, int, int>>pq;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                pq.push({matrix[i][j], i, j});

        vector<vector<int>>dp(m, vector<int>(n, -2)); //-2 not vis, -1 live node
        int ans = 0;

        while(!pq.empty()){
            auto [val, i, j] = pq.top();
            pq.pop();

            ans = max(ans, memo(i, j, matrix, dp, m, n));
        }

        return ans+1;
    }
};