// leet - 34
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int binarySearch(vector<int> nums, int target, bool left){
        int st = 0, end = nums.size() - 1;
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(nums[mid] == target){
                ans = mid;
                if(left)
                    end = mid - 1;
                else
                    st = mid + 1;
            }
            else if(nums[mid] > target)
                end = mid - 1;
            else
                st = mid + 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        ans.push_back(binarySearch(nums, target, true));
        ans.push_back(binarySearch(nums, target, false));

        return ans;
    }
};