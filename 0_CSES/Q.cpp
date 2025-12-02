#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    
    vector<vector<int>> dp(n, vector<int>(x + 1, INT_MAX));
    
    // Base case: sum 0 can always be made with 0 coins
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    // Base row initialization
    for (int j = 0; j <= x; j++) {
        if (j % coins[0] == 0)
            dp[0][j] = j / coins[0];
    }

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            int nottake = dp[i - 1][j];
            int take = INT_MAX;
            if (coins[i] <= j && dp[i][j - coins[i]] != INT_MAX)
                take = dp[i][j - coins[i]] + 1;

            dp[i][j] = min(nottake, take);
        }
    }

    // Output result
    if (dp[n - 1][x] != INT_MAX)
        cout << dp[n - 1][x];
    else
        cout << -1;

    return 0;
}
