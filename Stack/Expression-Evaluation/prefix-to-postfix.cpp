#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToPost(string pre_exp) {
        reverse(pre_exp.begin(), pre_exp.end());
        stack<string> st;
        
        for(char c : pre_exp){
            if(isalnum(c)){
                st.push(string(1, c));
            }else{
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                
                string new_string = op1 + op2 + c;
                st.push(new_string);
            }
        }
        
        return st.top();
    }
};