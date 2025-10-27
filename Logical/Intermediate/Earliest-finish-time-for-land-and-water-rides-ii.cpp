// leet - 3635
// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                            vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size(), 
        land = 1e9, water = 1e9, land_water = 1e9, water_land = 1e9;

        for (int i = 0; i < n; ++i) {
            land = min(land, landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < m; ++i) {
            water = min(water, waterStartTime[i] + waterDuration[i]);
            land_water = min(land_water, max(waterStartTime[i], land) + waterDuration[i]);
        }

        for (int i = 0; i < n; ++i) {
            water_land = min(water_land, max(landStartTime[i], water) + landDuration[i]);
        }

        return min(water_land, land_water);
    }
};
