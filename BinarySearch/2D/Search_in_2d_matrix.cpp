// leet - 74
// https://leetcode.com/problems/search-a-2d-matrix/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // search row
        int start = 0, end = n - 1;
        int row = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            row = mid;

            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] > target)
                end = mid - 1;
            else{
                if(matrix[mid][m-1] >= target)
                    break;
                start = mid + 1;
            }
        }

        // search column
        start = 0, end = m - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] > target)  
                end = mid - 1;
            else
                start = mid + 1;
        }

        return false;
    }
};