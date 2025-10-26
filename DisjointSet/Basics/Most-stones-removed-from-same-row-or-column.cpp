// leet - 947
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> par;

    int find(int x) {
        if (par[x] != x)
            par[x] = find(par[x]);
        return par[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) par[px] = py;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        par.resize(n);
        iota(par.begin(), par.end(), 0); // Initialize par[i] = i

        map<int, int> row, col;

        for (int i = 0; i < n; i++) {
            int r = stones[i][0];
            int c = stones[i][1];

            if (row.count(r)) unite(i, row[r]);
            else row[r] = i;

            if (col.count(c)) unite(i, col[c]);
            else col[c] = i;
        }

        int safeStones = 0;
        for (int i = 0; i < n; i++)
            if (find(i) == i)
                safeStones++;

        return n - safeStones;
    }
};
