#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToInfix(string pre_exp) {
        reverse(pre_exp.begin(), pre_exp.end());
        stack<string> st;
        
        for (char c : pre_exp) {
            if (isalpha(c) || isdigit(c)) {
                st.push(string(1, c));  // push operand
            } else {
                // operator: pop two operands
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                
                // combine into infix
                string newExp = "(" + op1 + c + op2 + ")";
                st.push(newExp);
            }
        }
        
        return st.top();
    }
};
