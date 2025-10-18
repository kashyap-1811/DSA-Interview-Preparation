#include <bits/stdc++.h>

using namespace std;

int climb(int n, vector<int>&dp)
{
    if(n < 0)
        return 0;
    if(n==0)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = climb(n-1, dp)+climb(n-2, dp)+climb(n-3, dp);
    return dp[n];
}

int main()
{
    int n = 5;
    vector<int>dp(n+1, -1);

    cout<<climb(n, dp);
    return 0;
}