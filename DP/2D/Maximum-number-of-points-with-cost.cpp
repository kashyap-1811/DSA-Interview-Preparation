// leet - 1937
// https://leetcode.com/problems/maximum-number-of-points-with-cost/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<long long> previousRow(points[0].begin(), points[0].end());

        // Process each row
        for (int row = 1; row < rows; ++row) {
            vector<long long> leftMax(cols);
            vector<long long> rightMax(cols);
            vector<long long> currentRow(cols);

            // Calculate left-to-right maximum
            leftMax[0] = previousRow[0];
            for (int col = 1; col < cols; ++col) {
                leftMax[col] = max(leftMax[col - 1] - 1, previousRow[col]);
            }

            // Calculate right-to-left maximum
            rightMax[cols - 1] = previousRow[cols - 1];
            for (int col = cols - 2; col >= 0; --col) {
                rightMax[col] = max(rightMax[col + 1] - 1, previousRow[col]);
            }

            // Calculate the current row's maximum points
            for (int col = 0; col < cols; ++col) {
                currentRow[col] = points[row][col] + max(leftMax[col], rightMax[col]);
            }

            // Update previousRow for the next iteration
            previousRow = currentRow;
        }

        return *max_element(previousRow.begin(), previousRow.end());
    }
};