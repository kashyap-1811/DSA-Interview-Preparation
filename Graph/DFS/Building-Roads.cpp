// https://cses.fi/problemset/task/1666/
#include <bits/stdc++.h>
using namespace std;
 
void DFS(int i, vector<vector<int>> &adj, vector<bool> &vis){
    vis[i] = true;
 
    for(int v : adj[i])
        if(!vis[v])
            DFS(v, adj, vis);
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>());
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<bool> vis(n+1, false);
    vector<int> new_connections;
    int last = -1;
 
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            last = i;
            new_connections.push_back(i);
            DFS(i, adj, vis);
        }
    }
 
    cout << new_connections.size() - 1 << endl;
    for(int i=1; i<new_connections.size(); i++){
        cout << new_connections[i-1] << " " << new_connections[i] << endl;
    }
 
    return 0;
}
