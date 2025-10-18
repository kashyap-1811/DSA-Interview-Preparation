#include <bits/stdc++.h>

using namespace std;

int unboundedKnapsack(vector<int>&val, vector<int>&wt, int &capacity)
{
    int n = val.size();
    vector<vector<int>>dp(n+1, vector<int>(capacity+1, 0));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=capacity; j++)
        {
            //exclude
            int not_take = dp[i-1][j];

            //include
            int take = 0;
            if(wt[i-1] <= j)
                take = val[i-1] + dp[i][j-wt[i-1]];

            dp[i][j] = max(take, not_take);
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=capacity; j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    return dp[n][capacity];
}

int main()
{
    vector<int>val = {15, 14, 10, 45, 30};
    vector<int>wt = {2, 5, 1, 3, 4};
    int capacity = 7;

    cout<<unboundedKnapsack(val, wt, capacity);
    return 0;
}