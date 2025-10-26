// leet - 827
// https://leetcode.com/problems/making-a-large-island/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& uid, int& id, int &count, int& n){
        count++;
        uid[i][j] = id;

        //up
        if(i-1>=0 && uid[i-1][j]==-1 && grid[i-1][j]==1)
            DFS(i-1, j, grid, uid, id, count, n);

        //down
        if(i+1<n && uid[i+1][j]==-1 && grid[i+1][j]==1)
            DFS(i+1, j, grid, uid, id, count, n);

        //left
        if(j-1>=0 && uid[i][j-1]==-1 && grid[i][j-1]==1)
            DFS(i, j-1, grid, uid, id, count, n);

        //right
        if(j+1<n && uid[i][j+1]==-1 && grid[i][j+1]==1)
            DFS(i, j+1, grid, uid, id, count, n);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> uid(n, vector<int>(n, -1));
        map<int, int>m;
        queue<pair<int, int>>q;
        int id = 2;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
                else if(uid[i][j] == -1){
                    int count = 0;
                    DFS(i, j, grid, uid, id, count, n);
                    m[id] = count;
                    id++;
                }
            }
        }

        if(q.empty())
            return n * n;

        int maxSize = 0;

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            set<int>s;
            
            //up
            if(i-1>=0 && grid[i-1][j]==1)
                s.insert({uid[i-1][j]});

            //down
            if(i+1<n && grid[i+1][j]==1)
                s.insert({uid[i+1][j]});

            //left
            if(j-1>=0 && grid[i][j-1]==1)
                s.insert({uid[i][j-1]});

            //right
            if(j+1<n && grid[i][j+1]==1)
                s.insert({uid[i][j+1]});

            int size = 1;
            for(auto it : s)
                size += m[it];

            maxSize = max(maxSize, size);
        }

        return maxSize;
    }
};