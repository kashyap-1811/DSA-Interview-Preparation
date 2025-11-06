// leet - 1514
// https://leetcode.com/problems/path-with-maximum-probability/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // build adjacency list: adj[u] = vector of (v, prob)
        vector<vector<pair<int,double>>> adj(n);
        for (size_t i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        // max probability to reach each node from start
        vector<double> best(n, 0.0);
        best[start_node] = 1.0;

        // max-heap of pairs (probability, node)
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [prob_u, u] = pq.top(); pq.pop();

            // If this entry is stale, skip
            if (prob_u < best[u]) continue;

            // early exit: best reached end
            if (u == end_node) return prob_u;

            for (auto &edge : adj[u]) {
                int v = edge.first;
                double w = edge.second;
                double cand = prob_u * w;
                if (cand > best[v]) {
                    best[v] = cand;
                    pq.push({cand, v});
                }
            }
        }

        return 0.0; // unreachable
    }
};
