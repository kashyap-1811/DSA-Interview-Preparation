#include <bits/stdc++.h>

using namespace std;

int fibo(int n, vector<int>&dp) //O(2^n) -> O(n)
{
    if(dp[n] != -1)
        return dp[n];

    if(n==0 || n==1){
        return dp[n] = n;
    }

    dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    return dp[n];
}

int fiboTabulation(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }

    vector<int>dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main()
{
    int n = 6;
    vector<int>dp(n+1, -1);
    cout<<"Memoization: "<<fibo(n, dp)<<endl;
    cout<<"Tabulation: "<<fiboTabulation(n)<<endl;
    return 0;
}