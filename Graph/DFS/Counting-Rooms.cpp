// https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
using namespace std;
 
void DFS(int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &vis){
    vis[i][j] = true;
 
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,-1,1,0};
 
    for(int k=0; k<4; k++){
        int u = i + dx[k];
        int v = j + dy[k];
 
        if(u>=0 && v>=0 && u<mat.size() && v<mat[0].size() && !vis[u][v] && mat[u][v]=='.')
            DFS(u, v, mat, vis);
    }
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }
 
    int count = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && mat[i][j] == '.'){
                DFS(i, j, mat, vis);
                count++;
            }
        }
    }
 
    cout << count;
 
    return 0;
}