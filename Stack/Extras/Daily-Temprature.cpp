// leet 739
// https://leetcode.com/problems/daily-temperatures/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        st.push(n-1);
        vector<int> ans;
        ans.push_back(0);

        for(int i=n-2; i>=0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            if(st.empty())  
                ans.push_back(0);
            else
                ans.push_back(st.top() - i);

            st.push(i);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};