// leet - 787
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n, vector<pair<int, int>>());

        for(auto edge : flights)
            adj[edge[0]].push_back({edge[1], edge[2]});

        queue<tuple<int, int, int>>q; //node, cost, stops
        vector<int>dist(n, INT_MAX);

        q.push({src, 0, -1});
        dist[src] = 0;

        while(!q.empty()){
            auto [u, cost, stops] = q.front();
            q.pop();

            for(auto &p : adj[u]){
                int v = p.first, price = p.second;
                if(dist[v]>cost+price && stops+1<=k){
                    dist[v] = cost + price;
                    q.push({v, dist[v], stops+1});
                }
            }
        }

        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};