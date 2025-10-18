// leet - 856
// https://leetcode.com/problems/score-of-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> st;

        for(char c : s){
            if(c == '(')
                st.push(0);
            else{
                int val = st.top();
                st.pop();

                int innerScore = 0;
                if(val == 0)
                    innerScore = 1;
                else
                    innerScore = 2 * val;
                
                if(!st.empty())
                    st.top() += innerScore;
                else
                    score += innerScore;
            }
        }

        return score;
    }
};