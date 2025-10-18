// leet - 2598
// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> remainder(value, -1);
        // sort(nums.begin(), nums.end());

        for(int i : nums){
            int rem = abs(i) % value;
            if(i < 0 && rem != 0){
                rem = value - rem; 
            }

            if(remainder[rem] == -1)
                remainder[rem] = rem;
            else
                remainder[rem] += value;
        }

        int minVal = INT_MAX;
        for(int i=0; i<value; i++){
            if(remainder[i] == -1)
                return i;
            else if(minVal > remainder[i] + value)
                minVal = remainder[i] + value;
        }

        return minVal;
    }
};