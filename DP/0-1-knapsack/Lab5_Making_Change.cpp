#include <bits/stdc++.h>

using namespace std;

int makingChangeHelper(vector<int>& denominations, int amount, int i, vector<vector<int>>&dp) {
    // Base case: if amount is 0, we need 0 coins
    if (amount == 0) return 0;

    // If no denominations are left and the amount is not 0, return INT_MAX (not possible)
    if (i == denominations.size()) return INT_MAX;

    //change if this subprogram is already soled or not
    if(dp[i][amount] != -1)     return dp[i][amount];

    // Exclude the current denomination
    int not_take = makingChangeHelper(denominations, amount, i + 1, dp);

    // Include the current denomination
    int take = INT_MAX;
    if (denominations[i] <= amount) {
        int result = makingChangeHelper(denominations, amount - denominations[i], i, dp);
        if (result != INT_MAX) {
            take = 1 + result; // Avoid overflow
        }
    }

    return dp[i][amount] = min(take, not_take);
}

int makingChangeMemo(vector<int>&denominations, int &amount)
{
    int i = 0;
    vector<vector<int>>dp(denominations.size()+1, vector<int>(amount+1, -1));
    return makingChangeHelper(denominations, amount, i, dp);
}

int makingChangeTab(vector<int>&denominations, int &amount)
{
    int n = denominations.size();
    vector<vector<int>>dp(n, vector<int>(amount+1, INT_MAX));

    for(int j=0; j<=amount; j++)
        if(j%denominations[0] == 0)
            dp[0][j] = j/denominations[0];
    
    for(int i=0; i<n; i++)
        dp[i][0] = 0;

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=amount; j++)
        {
            //exclude
            int not_take = dp[i-1][j];

            //include
            int take = INT_MAX;
            if(denominations[i] <= j){
                int result = dp[i][j-denominations[i]];
                if(result != INT_MAX)
                    take = 1 + result;
            }

            dp[i][j] = min(take, not_take);
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=amount; j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    return dp[n-1][amount];
}

int main()
{
    vector<int>denominations = {1, 4, 5};
    int amount = 8;

    cout<<makingChangeTab(denominations, amount);
    return 0;
}