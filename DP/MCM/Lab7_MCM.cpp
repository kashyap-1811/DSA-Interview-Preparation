#include <bits/stdc++.h>

using namespace std;

int MCM_TAB(vector<int>&mat)
{
    int n = mat.size();
    vector<vector<int>>dp(n, vector<int>(n, 0));

    for(int i=1; i<n; i++)
        dp[i][i] = 0;

    for(int len=2; len<n; len++)
    {
        for(int i=1; i<=n-len; i++)
        {
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++)
            {
                int cost = dp[i][k] + dp[k+1][j] + mat[i-1]*mat[k]*mat[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[1][n-1];
}

int MCM_REC_HELPER(vector<int>&mat, int i, int j, vector<vector<int>>&dp)
{
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for(int k=i; k<j; k++)
    {
        int cost = MCM_REC_HELPER(mat, i, k, dp) + MCM_REC_HELPER(mat, k+1, j, dp)
                    + mat[i-1]*mat[k]*mat[j];
        if(ans > cost)
            ans = cost;
    }
    return dp[i][j] = ans;
}

int MCM_REC(vector<int>&mat)
{
    vector<vector<int>>dp(mat.size(), vector<int>(mat.size(), -1));
    return MCM_REC_HELPER(mat, 1, mat.size()-1, dp);
}

int main()
{
    vector<int>mat = {1, 2, 3, 4, 3};
    // cout<<MCM_REC(mat)<<endl;
    cout<<MCM_TAB(mat)<<endl;
    return 0;
}
