#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int precedence(char c){
        switch(c){
            case '^': return 3;
            case '*': case '/': return 2;
            case '+': case '-': return 1;
            default: return -1;
        }    
    }
    
    bool isRightAssociative(char c){
        return c != '^';
    }
    
    string infixToPrefix(string &s) {
        reverse(s.begin(), s.end());
        stack<char> st;
        string result = "";
        
        for(char &c : s){
            if(isalnum(c)){
                result += c;  // operand
            }
            else if(c == ')'){  // originally '('
                st.push(c);
            }
            else if(c == '('){  // originally ')'
                while(!st.empty() && st.top() != ')'){
                    result += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop(); // pop ')'
            }
            else {  // operator
                while(!st.empty() && 
                      ((precedence(c) < precedence(st.top())) ||
                       (precedence(c) == precedence(st.top()) && !isRightAssociative(c)))) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
