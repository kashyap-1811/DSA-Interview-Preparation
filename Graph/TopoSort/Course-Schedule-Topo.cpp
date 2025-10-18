// https://cses.fi/problemset/task/1679/
#include <bits/stdc++.h>
 
using namespace std;
 
void DFS(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &rec, stack<int> &s){
    vis[u] = true;
    rec[u] = true;
 
    for(int v : adj[u]){
        if(rec[v]){
            cout << "IMPOSSIBLE";
            exit(0);
        }else if(!vis[v])
            DFS(v, adj, vis, rec, s);
    }
 
    rec[u] = false;
    s.push(u);
}
 
void topoSort(int n, vector<vector<int>> &adj){
    vector<bool> vis(n, false), rec(n, false);
    stack<int> s;
 
    for(int i=0; i<n; i++){
        if(!vis[i])
            DFS(i, adj, vis, rec, s);
    }
 
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
 
    // reverse(ans.begin(), ans.end());
    for(int i : ans)
        cout << i + 1 << " ";
}
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> adj(n, vector<int>());
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }
 
    topoSort(n, adj);
    return 0;
}