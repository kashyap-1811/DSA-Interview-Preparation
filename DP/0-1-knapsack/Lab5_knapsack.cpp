#include <bits/stdc++.h>

using namespace std;

int knapSackTab(int capacity, vector<int> &val, vector<int> &wt) {
        // Create a DP table of size (n+1) x (capacity+1)
        vector<vector<int>> dp(val.size() + 1, vector<int>(capacity + 1, 0));

        // Bottom-up calculation
        for (int i = 1; i <= val.size(); i++) {
            for (int j = 1; j <= capacity; j++) {
                // Option 1: Do not take the current item
                int not_take = dp[i-1][j];

                // Option 2: Take the current item (if it fits)
                int take = 0;
                if (wt[i-1] <= j)
                    take = val[i-1] + dp[i-1][j - wt[i-1]];

                // Take the maximum of the two options
                dp[i][j] = max(take, not_take);
            }
        }

        // The maximum value is stored in dp[n][capacity]
        return dp[val.size()][capacity];
}

int knapSackHelper(int capacity, vector<int>& val, vector<int>& wt, int i, vector<vector<int>>& dp) {
        // Base cases
        if (i == val.size() || capacity == 0)
            return 0;

        // If the result is already computed, return it
        if (dp[i][capacity] != -1)
            return dp[i][capacity];

        // Take the current item if it fits in the knapsack
        int sum1 = 0;
        if (capacity >= wt[i])
            sum1 = val[i] + knapSackHelper(capacity - wt[i], val, wt, i + 1, dp);

        // Skip the current item
        int sum2 = knapSackHelper(capacity, val, wt, i + 1, dp);

        // Store the result in dp and return
        return dp[i][capacity] = max(sum1, sum2);
}

int knapSackMemo(int capacity, vector<int>& val, vector<int>& wt) {
        // Create a DP table initialized with -1
        vector<vector<int>> dp(val.size(), vector<int>(capacity + 1, -1));
        return knapSackHelper(capacity, val, wt, 0, dp);
}

int main()
{
    vector<int>wt = {5, 4, 6, 3};
    vector<int>val = {10, 40, 30, 50};
    int capacity = 5;

    cout<<"KnapSack Memoization: "<<knapSackMemo(capacity, val, wt)<<endl;
    cout<<"KnapSack Tabulation: "<<knapSackTab(capacity, val, wt)<<endl;
    return 0;
}