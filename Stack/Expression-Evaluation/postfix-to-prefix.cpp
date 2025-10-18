#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string> st;
        
        for(char c : post_exp){
            if(isalnum(c)){
                st.push(string(1, c));
            }else{
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                
                st.push(string(1,c) + op2 + op1);
            }
        }
        
        return st.top();
    }
};