// leet - 2101
// https://leetcode.com/problems/detonate-the-maximum-bombs/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    void dfs(int node,vector<int>& visited,vector<vector<int>>& adj){
        visited[node]=1;

        for(auto it: adj[node]){
            if(visited[it]==0){
                dfs(it,visited,adj);
            }
        }
    }

    bool inRange(long long x1, long long y1, long long r1,
                 long long x2, long long y2) {
        long long dx = x2 - x1;
        long long dy = y2 - y1;
        return dx * dx + dy * dy <= r1 * r1;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n-1; i++){
            long long x1=bombs[i][0];
            long long y1=bombs[i][1];
            long long r1=bombs[i][2];
            for(int j=i+1; j<n; j++){
                long long x2=bombs[j][0];
                long long y2=bombs[j][1];
                long long r2=bombs[j][2];
                if (inRange(x1, y1, r1, x2, y2)) {
                    adj[i].push_back(j);
                }
                if (inRange(x2, y2, r2, x1, y1)) {
                    adj[j].push_back(i);
                }
            }
        }
        
        int maxi=0;
        
        for(int i=0; i<n; i++){
            int start=i;
            vector<int> visited(n,0);
            dfs(i,visited,adj);
            int count=0;
            for(int i=0; i<n; i++){
                if(visited[i]==1) count++;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};