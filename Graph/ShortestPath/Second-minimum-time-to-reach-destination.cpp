// leet - 2045
// https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Store two shortest arrival times for each node
        vector<int> first(n + 1, INT_MAX), 
                    second(n + 1, INT_MAX);

        queue<pair<int, int>> q;
        q.push({1, 0}); // node, current_time
        first[1] = 0;

        while (!q.empty()) {
            auto [u, currTime] = q.front();
            q.pop();

            for (int v : adj[u]) {
                int newTime = currTime;

                // Wait if the signal is red
                if ((newTime / change) % 2 == 1)
                    newTime = (newTime / change + 1) * change;

                newTime += time;

                // Check and update first or second time
                if (newTime < first[v]) {
                    second[v] = first[v];
                    first[v] = newTime;
                    q.push({v, newTime});
                } else if (newTime > first[v] && newTime < second[v]) {
                    second[v] = newTime;
                    q.push({v, newTime});
                }
            }
        }

        return second[n];
    }
};
