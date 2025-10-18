// leet - 2104
// https://leetcode.com/problems/sum-of-subarray-ranges/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevGreater(n, -1), nextGreater(n, n);
        vector<int> prevSmaller(n, -1), nextSmaller(n, n);

        stack<int> st1, st2;

        // find for prev
        st1.push(0); st2.push(0);
        for(int i=1; i<n; i++){
            while(!st1.empty() && nums[st1.top()] > nums[i])
                st1.pop();
            
            if(!st1.empty())
                prevSmaller[i] = st1.top();
            st1.push(i);

            while(!st2.empty() && nums[st2.top()] < nums[i])
                st2.pop();

            if(!st2.empty())
                prevGreater[i] = st2.top();
            st2.push(i);
        }

        while(!st1.empty())
            st1.pop();
        while(!st2.empty())
            st2.pop();

        // find for next
        st1.push(n-1); st2.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st1.empty() && nums[st1.top()] >= nums[i])
                st1.pop();
            
            if(!st1.empty())
                nextSmaller[i] = st1.top();
            st1.push(i);

            while(!st2.empty() && nums[st2.top()] <= nums[i])
                st2.pop();

            if(!st2.empty())
                nextGreater[i] = st2.top();
            st2.push(i);
        }

        long long total = 0;
        for(int i=0; i<n; i++){
            // how many times it is max
            total += (1LL * nums[i] * (nextGreater[i] - i) * (i - prevGreater[i]));

            // how many times it is min
            total -= (1LL * nums[i] * (nextSmaller[i] - i) * (i - prevSmaller[i]));
        }

        return total;
    }
};