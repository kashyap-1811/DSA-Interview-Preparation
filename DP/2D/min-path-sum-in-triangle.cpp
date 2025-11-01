// leet - 120
// https://leetcode.com/problems/triangle/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle[0].begin(), triangle[0].end());

        for(int i=1; i<triangle.size(); i++){
            int n = triangle[i].size();
            vector<int> temp(n, -1);

            temp[0] = dp[0] + triangle[i][0];
            for(int j=1; j<n-1; j++)
                temp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            temp[n-1] = dp[n-2] + triangle[i][n-1];

            dp = temp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};