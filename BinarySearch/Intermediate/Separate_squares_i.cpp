// https://leetcode.com/problems/separate-squares-i/description/

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double minY = 0;
        double maxY = 2e9;

        for (int i = 0; i < 60; i++) {
            double mid = (minY + maxY) / 2.0;

            double areaAbove = 0;
            double areaBelow = 0;

            for (auto &s : squares) {
                double y = s[1];
                double l = s[2];

                // Completely below
                if (y + l <= mid) {
                    areaBelow += l * l;
                }

                // Completely above
                else if (y >= mid) {
                    areaAbove += l * l;
                }

                // Line cuts the square
                else {
                    areaBelow += l * (mid - y);
                    areaAbove += l * (y + l - mid);
                }
            }

            if (areaAbove > areaBelow)
                minY = mid;
            else
                maxY = mid;
        }

        return maxY;
    }
};