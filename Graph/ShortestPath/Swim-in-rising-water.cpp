// leet - 778
// https://leetcode.com/problems/swim-in-rising-water/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>>vis(n, vector<bool>(n, false));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>pq;
        pq.push({grid[0][0], 0, 0});

        vector<int>dx = {-1, 1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};

        while(!pq.empty()){
            auto [time, x, y] = pq.top();
            pq.pop();

            if(x==n-1 && y==n-1)    
                return time;

            if(vis[x][y])
                continue;

            vis[x][y] = true;

            for(int i=0; i<4; i++){
                int r = x + dx[i];
                int c = y + dy[i];

                if(r<n && r>=0 && c<n && c>=0 && !vis[r][c])
                    pq.push({max(time, grid[r][c]), r, c});
            }
        }

        return -1;
    }
};