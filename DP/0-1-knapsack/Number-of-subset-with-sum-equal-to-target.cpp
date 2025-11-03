// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
  public:
    int memo(int i, int sum, vector<int> &arr, int &target, vector<vector<int>> &dp){
        if(sum > target)
            return 0;
            
        if(i == -1)
            return sum == target ? 1 : 0;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        // not take
        int notTake = memo(i - 1, sum, arr, target, dp);
        
        // take
        int take = memo(i - 1, sum + arr[i], arr, target, dp);
        
        return dp[i][sum] = notTake + take;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        // memoizaation
        // return memo(n-1, 0, arr, target, dp);
        
        // tabulation
        // Assuming dp is a 2D vector/array of size n x (target + 1), initialized to 0.
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        // --- Corrected Initialization for row i=0 ---
        
        // Handle the first element (i=0) separately
        // Check if the first element is 0
        if (arr[0] == 0) {
            // If arr[0] is 0, we have two ways to get sum 0:
            // 1. Don't take the 0
            // 2. Take the 0
            dp[0][0] = 2;
        } else {
            // If arr[0] is not 0, we have one way to get sum 0:
            // 1. Don't take the element
            dp[0][0] = 1;
        }
        
        // If the first element is not 0 AND it's within the target bound
        if (arr[0] != 0 && arr[0] <= target) {
            // We have one way to get the sum arr[0]:
            // 1. Take the element
            dp[0][arr[0]] = 1;
        }
        
        // --- Main Loop (This part was correct) ---
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                // Not take the current element
                // The number of ways is the same as the ways from the previous row
                int notTake = dp[i - 1][j];
                
                // Take the current element
                int take = 0;
                if (arr[i] <= j) {
                    // The number of ways is from the previous row at sum (j - arr[i])
                    take = dp[i - 1][j - arr[i]];
                }
                
                // Total ways is the sum of taking and not taking
                // Note: If counts can be large, you might need modulo arithmetic here
                dp[i][j] = notTake + take;
            }
        }
        
        return dp[n - 1][target];
    }
};