// leet - 153
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        while(st < end){
            int mid = st + (end - st) / 2;

            if(nums[mid] <= nums[end])
                end = mid;
            else
                st = mid + 1;
        }
        
        // No of times array has been sorted
        // cout << st << endl;
        return nums[st];
    }
};