// leet - 496
// https://leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int, int> m;
        stack<int> st;

        m[nums2[n-1]] = -1;
        st.push(nums2[n-1]);

        for(int i=n-2; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i])
                st.pop();
            
            if(st.empty())
                m[nums2[i]] = -1;
            else
                m[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++)
            ans.push_back(m[nums1[i]]);
        
        return ans;
    }
};