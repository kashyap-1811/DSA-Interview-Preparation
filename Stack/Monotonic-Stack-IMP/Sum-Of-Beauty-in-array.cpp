// leet - 2012
// https://leetcode.com/problems/sum-of-beauty-in-the-array/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<bool> prevGreater(n, false);
        vector<bool> nextSmaller(n, false);

        stack<int> st;

        // for prev smaller
        st.push(nums[0]);
        for(int i=1; i<n; i++){
            while(!st.empty() && st.top() < nums[i])
                st.pop();
            
            if(!st.empty())
                prevGreater[i] = true;
            st.push(nums[i]);
        }

        while(!st.empty())
            st.pop();

        // for next Greater
        st.push(nums[n-1]);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && st.top() > nums[i])
                st.pop();

            if(!st.empty())
                nextSmaller[i] = true;
            st.push(nums[i]);
        }

        int count = 0;
        for(int i=1; i<n-1; i++){
            if(prevGreater[i] || nextSmaller[i]){
                if(nums[i-1] < nums[i] && nums[i] < nums[i+1])
                    count++;
            }else{
                count += 2;
            }
        }
            
        return count;
    }
};