// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V, vector<pair<int, int>>());
        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        int totalCost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0,0});
        vector<bool> vis(V, false);
        
        while(!pq.empty()){
            auto [currCost, u] = pq.top();
            pq.pop();
            
            if(vis[u])  
                continue;
            
            vis[u] = true;
            totalCost += currCost;
            
            for(auto [v, wt] : adj[u]){
                if(!vis[v]){
                    pq.push({wt, v});
                }
            }
        }
        
        return totalCost;
    }
};