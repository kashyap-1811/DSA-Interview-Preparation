// leet - 907
// https://leetcode.com/problems/sum-of-subarray-minimums/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevSmaller(n, -1);
        vector<int> nextSmaller(n, n);

        // find prev smaller
        stack<int> st;
        st.push(0);
        for(int i=1; i<n; i++){
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            
            if(!st.empty())
                prevSmaller[i] = st.top();
            
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // find next smaller
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            
            if(!st.empty())
                nextSmaller[i] = st.top();
            
            st.push(i);
        }

        long long total = 0;
        for(int i=0; i<n; i++){
            total = (total +  (1LL * nums[i] * (i - prevSmaller[i]) * (nextSmaller[i] - i)) % mod) % mod;
        }

        return total;
    }
};