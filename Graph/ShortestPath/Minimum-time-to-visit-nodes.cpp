// leet - 3112
// https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> ans(n, -1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, 0});
        ans[0] = 0;

        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            if (time > ans[u]) continue;  // skip outdated entries

            for (auto &[v, wt] : adj[u]) {
                int newTime = time + wt;
                if (newTime < disappear[v] && (ans[v] == -1 || newTime < ans[v])) {
                    ans[v] = newTime;
                    pq.push({newTime, v});
                }
            }
        }

        return ans;
    }
};
