// Cses - 1668 
// https://cses.fi/problemset/task/1668/
 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> colors(n, -1);

    for(int i=0; i<n; i++){
        if(colors[i] == -1){
            queue<int> q;
            q.push(i);
            colors[i] = 0;

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int v : adj[u]){
                    if(colors[v] == -1){
                        colors[v] = !colors[u];
                        q.push(v);
                    }else if(colors[v] == colors[u]){
                        cout << "IMPOSSIBLE";
                        exit(0);
                    }
                }
            }
        }
    }

    for(int i : colors)
        cout << i + 1 << " ";
    
    return 0;
}