// leet - 240
// https://leetcode.com/problems/search-a-2d-matrix-ii/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1, n = matrix.size();
        while (row < n && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }
};