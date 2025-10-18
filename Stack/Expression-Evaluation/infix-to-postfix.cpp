#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int precedence(char c) {
        switch (c) {
            case '^': return 3;
            case '*': return 2;
            case '/': return 2;
            case '+': return 1;
            case '-': return 1;
            default:  return -1;
        }
    }

    bool isRightAssociative(char c) {
        return c == '^';
    }

    string infixToPostfix(string &s) {
        stack<char> st;
        string result;

        for (char c : s) {
            // operand
            if (isalnum(c)) {
                result += c;
            }

            // opening parenthesis
            else if (c == '(') {
                st.push(c);
            }

            // closing parenthesis
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop '('
            }

            // operator
            else {
                while (!st.empty() && precedence(st.top()) > precedence(c) ||
                       (!st.empty() && precedence(st.top()) == precedence(c) && !isRightAssociative(c))) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
