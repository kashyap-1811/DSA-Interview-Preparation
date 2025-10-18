// leet - 2751
// https://leetcode.com/problems/robot-collisions/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int, int> m;
        for(int i=0; i<positions.size(); i++)
            m[positions[i]] = i;
        
        stack<int> st;

        for(auto p : m){
            int idx = p.second;
            if(directions[idx] == 'L'){
                while(!st.empty() && directions[st.top()] == 'R' && healths[st.top()] < healths[idx]){
                    st.pop();
                    healths[idx]--;
                }

                if(st.empty() || directions[st.top()] == 'L')
                    st.push(idx);
                else if(healths[st.top()] == healths[idx])
                    st.pop();
                else
                    healths[st.top()]--;
            }else{
                st.push(idx);
            }
        }

        unordered_set<int> s;
        while(!st.empty()){
            s.insert({st.top()});
            st.pop();
        }

        vector<int> ans;
        for(int i=0; i<positions.size(); i++){
            if(s.count(i))
                ans.push_back(healths[i]);
        }

        return ans;
    }
};