// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if ((sum + d) % 2 != 0 || sum < d)
            return 0;

        int target = (sum + d) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] = (dp[j] + dp[j - num]);
            }
        }

        return dp[target];
    }
};
