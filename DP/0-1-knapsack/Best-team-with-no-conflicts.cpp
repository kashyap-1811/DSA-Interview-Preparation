// leet - 1626
// https://leetcode.com/problems/best-team-with-no-conflicts/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<vector<int>> dp;

    int memo(int i, int highestScoreIdx, vector<vector<int>> &player){
        if(i == player.size())
            return 0;
        if(dp[i][highestScoreIdx + 1] != -1)
            return dp[i][highestScoreIdx + 1];
        
        // not take
        int notTake = memo(i + 1, highestScoreIdx, player);

        // take
        int take = 0;
        if(highestScoreIdx == -1 || player[i][1] >= player[highestScoreIdx][1]){
            take = player[i][1] + memo(i + 1, i, player);
        }

        return dp[i][highestScoreIdx + 1] = max(take, notTake);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vector<int>> player(n, vector<int>(2, 0));

        for(int i=0; i<n; i++){
            player[i][0] = ages[i];
            player[i][1] = scores[i];
        }
        sort(player.begin(), player.end());

        dp.resize(n, vector<int>(n + 1, -1));
        return memo(0, -1, player);
    }
};