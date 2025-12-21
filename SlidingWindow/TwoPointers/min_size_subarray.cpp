// leet - 209
// https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2&envId=sliding-window
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0;
        int minLen = INT_MAX;
        int currSum = 0;

        while(r < nums.size()){
            currSum += nums[r];

            while(l<=r && currSum >= target){
                minLen = min(minLen, r - l + 1);
                currSum -= nums[l];
                l++;
            }

            r++;
        }

        return minLen != INT_MAX ? minLen : 0;
    }
};