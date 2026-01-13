// leet - 2091
// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;

        int maxIdx = 0, minIdx = 0;
        for(int i=1; i<n; i++){
            if(nums[i] > nums[maxIdx])
                maxIdx = i;
            else if(nums[i] < nums[minIdx])
                minIdx = i;
        }

        int deletions = 0;
        int minimumFromLeft = minIdx + 1, minimumFromRight = n - minIdx;
        int maximumFromLeft = maxIdx + 1, maximumFromRight = n - maxIdx;

        int one = minimumFromLeft + min(maximumFromRight, abs(minimumFromLeft - maximumFromLeft));
        int two = minimumFromRight + min(maximumFromLeft, abs(minimumFromRight - maximumFromRight));
        int three = maximumFromLeft + min(minimumFromRight, abs(minimumFromLeft - maximumFromLeft));
        int four = maximumFromRight + min(minimumFromLeft, abs(minimumFromRight - maximumFromRight));

        return min({one, two, three, four});
    }
};