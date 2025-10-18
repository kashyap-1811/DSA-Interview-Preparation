// leet - 53
// https://leetcode.com/problems/maximum-subarray/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int lm = INT_MIN;
        int gm = INT_MIN;
        int start = 0;
        int tempStart = 0;
        int end = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(lm < 0){
                tempStart = i;
                lm = nums[i];
            }else{
                lm += nums[i];
            }

            if(gm < lm)
            {
                start = tempStart;
                end = i;
                gm = lm;
            }
        }

        // cout<<start<<" "<<end;

        return gm;
    }
};