// leet - 2401
// https://leetcode.com/problems/longest-nice-subarray/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> bits(30, -1);
        int i = 0;
        int maxLength = 1;

        for (int j = 0; j < nums.size(); j++) {
            int num = nums[j];
            int k = 0;

            while (num != 0) {
                int bit = num % 2;

                if (bit == 1) {
                    if (bits[k] != -1 && i <= bits[k])
                        i = bits[k] + 1;
                    bits[k] = j;
                }

                k++;
                num /= 2;
            }

            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};