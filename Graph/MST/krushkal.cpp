// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
  public:
    vector<int> par;
    vector<int> rank;
    
    int find(int x){
        if(x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    
    bool unite(int u, int v){
        int parU = find(u);
        int parV = find(v);
        
        if(parU == parV) return false;
        
        if(rank[parU] < rank[parV])
            par[parU] = parV;
        else if(rank[parV] < rank[parU])
            par[parV] = parU;
        else{
            par[parV] = parU;
            rank[parU]++;
        }
        
        return true;
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        par.resize(V);
        rank.resize(V);
        for(int i=0; i<V; i++){
            par[i] = i;
            rank[i] = 0;
        }
        
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });
        
        int sum = 0;
        for(auto e : edges){
            auto u = e[0], v = e[1], wt = e[2];
            if(unite(u, v))
                sum += wt;
        }
        
        return sum;
    }
};