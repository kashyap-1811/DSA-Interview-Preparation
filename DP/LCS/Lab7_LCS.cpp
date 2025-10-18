#include <bits/stdc++.h>

using namespace std;

int LCS(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    // elemenets are equal
    if (text1[i] == text2[j])
        ans = 1 + LCS(text1, text2, i - 1, j - 1, dp);

    // elements are not equal
    else
        ans = max(LCS(text1, text2, i - 1, j, dp), LCS(text1, text2, i, j - 1, dp));

    return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>>dp(m, vector<int>(n, -1));
    return LCS(text1, text2, m-1, n-1, dp);
}

int LCSTabu(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    vector<vector<bool>> sol(m + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ans = 0;
            if (text1[i - 1] == text2[j - 1])
            {
                ans = 1 + dp[i - 1][j - 1];
                sol[i][j] = true;
            }
            else
                ans = max(dp[i - 1][j], dp[i][j - 1]);

            dp[i][j] = ans;
        }
    }

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }

    int i=1, j=1;
    string ans = "";
    while(i<=m && j<=n)
    {
        if(sol[i][j] == false)
                i++;
        else{
            ans += text1[i-1];
            j++;
        }
    }
    cout<<ans<<endl;;
    return dp[m][n];
}


int main()
{
    string s1="kashyap", s2="kashu";

    cout<<LCSTabu(s1, s2);
    return 0;
}