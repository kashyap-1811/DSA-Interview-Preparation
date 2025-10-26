// leet - 305
// https://leetcode.com/problems/number-of-islands-ii/
 
#include <bits/stdc++.h>
using namespace std;
 
// u: 2
class Solution {
public:
    vector<int> parent;

    int find(int id){
        if(parent[id] == id)
            return id;
        return parent[id] = find(parent[id]);
    }

    bool unite(int id1, int id2){
        int par1 = find(id1);
        int par2 = find(id2);

        if(par1 == par2)
            return false;

        parent[par1] = par2;    
        return true;
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int groups = 0;
        int id = 0;
        vector<int> ans;

        map<pair<int, int>, int> groupId;
        vector<int> dx = {-1, 1, 0, 0},
                    dy = {0, 0, -1, 1};

        for(auto &p : positions){
            int x = p[0], y = p[1];

            if(groupId.count({x, y})){
                ans.push_back(groups);
                continue;
            }

            groupId[{x, y}] = id;
            parent.push_back(id++);
            groups++;

            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && ny>=0 && nx<m && ny<n && 
                    groupId.count({nx, ny}) && 
                    unite(groupId[{nx, ny}], groupId[{x,y}]))
                        groups--;
            }
            ans.push_back(groups);
        }

        return ans;
    }
};