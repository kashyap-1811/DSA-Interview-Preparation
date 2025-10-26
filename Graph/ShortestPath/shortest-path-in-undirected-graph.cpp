// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int v : adj[u]){
                if(dist[v] == -1 || dist[u] + 1 < dist[v]){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        
        return dist;
    }
};