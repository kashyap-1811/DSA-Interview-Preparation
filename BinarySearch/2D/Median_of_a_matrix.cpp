// leet - 2387
// https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int low = grid[0][0];
        int high = grid[0][n-1];
        // finding lowest and highest among matrix
        for(int i=0; i<m; i++){
            low = min(low, grid[i][0]);
            high = max(high, grid[i][n-1]);
        }

        // finding median
        while(low < high){
            // middle value
            int mid = low + (high - low) / 2;

            // number of elements <= mid
            int x = 0;

            for(int i=0; i<m; i++){
                int lowIdx = 0, highIdx = n-1;

                while(lowIdx <= highIdx){
                    int midIdx = lowIdx + (highIdx - lowIdx) / 2;

                    if(grid[i][midIdx] > mid)
                        highIdx = midIdx - 1;
                    else
                        lowIdx = midIdx + 1;
                }

                x += lowIdx;
            }

            if(x > (m * n) / 2)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};