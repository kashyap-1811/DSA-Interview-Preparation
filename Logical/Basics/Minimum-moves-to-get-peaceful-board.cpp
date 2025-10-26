// leet - 3189
// https://leetcode.com/problems/minimum-moves-to-get-a-peaceful-board/
 
#include <bits/stdc++.h>
using namespace std;
 
// u: 2
class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int n = rooks.size();
        int moves = 0;

        sort(rooks.begin(), rooks.end());
        for(int i=0; i<n; i++){
            moves += abs(rooks[i][0] - i);
            rooks[i][0] = i;
        }

        sort(rooks.begin(), rooks.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        for(int i=0; i<n; i++){
            moves += abs(rooks[i][1] - i);
            rooks[i][1] = i;
        }

        return moves;
    }
};