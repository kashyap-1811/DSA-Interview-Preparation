#include <bits/stdc++.h>

using namespace std;

int nCr(int n, int r) 
{
    if(n < r)
      return 0;
    vector<vector<int>>dp;
    for(int i=0; i<=n; i++)
    {
        vector<int>temp;
        for(int j=0; j<=i && j<=r; j++)
        {
            if(i==j || j==0)
                temp.push_back(1);
            else
                temp.push_back(dp[i-1][j] + dp[i-1][j-1]);
        }
        dp.push_back(temp);
    }
          
    for(int i=0; i<dp.size(); i++)
    {
        for(int j=0; j<dp[i].size(); j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
          
    return dp[n][r];
}

int main()
{
    cout<<nCr(9, 8);
    return 0;
}