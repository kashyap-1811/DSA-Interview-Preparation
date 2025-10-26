// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;
 
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V, vector<pair<int, int>>());
        for(auto e : edges)
            adj[e[0]].push_back({e[1], e[2]});
        
        vector<int> dist(V, -1);
        dist[0] = 0;
        priority_queue<int, vector<int>, greater<>> q;
        q.push(0);
        
        while(!q.empty()){
            int u = q.top();
            q.pop();
            
            for(auto p : adj[u]){
                int v = p.first, wt = p.second;
                if(dist[v] == -1 || dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    q.push(v);
                }
            }
        }
        
        return dist;
    }
};
