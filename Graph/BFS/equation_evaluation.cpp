// leet - 399
// https://leetcode.com/problems/evaluate-division/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    unordered_map<string, unordered_map<string, double>> adj;

    double bfs(string c, string d) {
        if(!adj.count(c) || !adj.count(d))
            return -1;
        
        double ans = -1;

        queue<pair<string, double>> q;
        unordered_set<string> st;
        q.push({c, 1});
        st.insert(c);

        while(!q.empty()) {
            auto [curr, val] = q.front();
            q.pop();

            if(curr == d) {
                if(ans != -1)
                    return -1;
                ans = val;
                continue;
            }
            
            for(auto [nei, wt] : adj[curr]) {
                if(!st.count(nei)) {
                    q.push({nei, val * wt});
                    st.insert(nei);
                }
            }
        }

        return ans;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0; i<equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            if(!adj.count(a))
                adj.insert({a, {}});
            adj[a].insert({b, val});

            if(!adj.count(b))
                adj.insert({b, {}});
            adj[b].insert({a, 1/val});
        }

        vector<double> ans;

        for(auto q : queries) {
            auto c = q[0];
            auto d = q[1];

            ans.push_back(bfs(c, d));
        }

        return ans;
    }
};