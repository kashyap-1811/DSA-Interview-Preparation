#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        
        for(char c : exp){
            if(isalnum(c)){
                st.push(string(1, c));
            }else{
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                
                st.push("(" + op2 + c + op1 + ")");
            }
        }
        
        return st.top();
    }
};