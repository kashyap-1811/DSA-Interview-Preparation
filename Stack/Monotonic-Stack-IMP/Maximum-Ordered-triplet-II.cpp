// leet - 2874
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevGlobalMax(n, 0);
        vector<int> nextGlobalMax(n, n-1);

        // find prev Global Max
        int maxVal = nums[0];
        for(int i=1; i<n; i++){
            prevGlobalMax[i] = maxVal;
            maxVal = max(maxVal, nums[i]);
        }

        // Find next Global Max
        maxVal = nums[n-1];
        for(int i=n-2; i>=1; i--){
            nextGlobalMax[i] = maxVal;
            maxVal = max(maxVal, nums[i]);
        }

        long long ans = 0;
        for(int i=1; i<n-1; i++)
            ans = max(ans, 1LL * (prevGlobalMax[i] - nums[i]) * nextGlobalMax[i]);
        
        return ans;
    }
};