// https://cses.fi/problemset/task/1667/
#include <bits/stdc++.h>
using namespace std;
 
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
    vector<int> parent(n+1, -1);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    bool found = false;
 
    while(!q.empty()){
        int curr = q.front();
        q.pop();
 
        if(curr == n){
            found = true;
            break;
        }
        
        for(int v : adj[curr]){
            if(!vis[v]){
                q.push(v);
                vis[v] = true;
                parent[v] = curr;
            }
        }
    }
 
    if(!found){
        cout << "IMPOSSIBLE";
        exit(0);
    }
 
    vector<int> ans;
    int curr = n;
 
    while(curr != 1){
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    
    cout << ans.size() << endl;
    for(int i : ans)
        cout << i << " ";
 
    return 0;
}