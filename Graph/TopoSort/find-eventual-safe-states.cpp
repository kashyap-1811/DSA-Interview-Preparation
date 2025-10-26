// leet - 802
// https://leetcode.com/problems/find-eventual-safe-states/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool DFS(int u, vector<vector<int>> &adj, vector<bool> &vis, set<int> &safe){
        vis[u] = true;

        for(int v : adj[u]){
            if(!vis[v]){
                if(!DFS(v, adj, vis, safe))
                    return false;
            }else if(!safe.count(v))
                return false;
        }

        safe.insert({u});
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<graph.size(); i++)
            for(int j=0; j<graph[i].size(); j++)
                adj[i].push_back(graph[i][j]);
        
        set<int> safe;
        for(int i=0; i<n; i++)
            if(adj[i].size() == 0)
                safe.insert({i});
        
        if(safe.size() == 0)
            return vector<int>{};
        
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i])
                DFS(i, adj, vis, safe);
        }

        vector<int> ans;
        for(int node : safe)
            ans.push_back(node);

        return ans;
    }
};