// leet - 32
// https://leetcode.com/problems/longest-valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> valid(s.size(), false);
        stack<int> st;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(')
                st.push(i);
            else if(!st.empty()){
                int idx = st.top();
                st.pop();
                valid[idx] = true;
                valid[i] = true;
            }
        }

        int maxLength = 0, len = 0;
        for(bool b : valid){
            if(b)
                len++;
            else
                len = 0;

            maxLength = max(maxLength, len);
        }

        return maxLength;
    }
};