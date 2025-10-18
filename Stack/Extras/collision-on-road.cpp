// leet - 2211
// https://leetcode.com/problems/count-collisions-on-a-road/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int count = 0;  
        stack<char> st;

        for(char c : directions){
            if(c == 'R'){
                st.push(c);
            }else if(c == 'L' && !st.empty()){
                if(st.top() == 'R')
                    count += 2;
                else
                    count += 1;

                st.pop();
                c = 'S';
            }

            if(c == 'S'){
                while(!st.empty() && st.top() == 'R'){
                    count++;
                    st.pop();
                }

                st.push(c);
            }
        }

        return count;
    }
};