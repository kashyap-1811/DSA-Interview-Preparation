// leet - 986
// https://leetcode.com/problems/interval-list-intersections/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        vector<vector<int>> ans;
        int i=0, j=0;

        while(i<n && j<m){
            // find overlapping interval
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            if(start <= end)
                ans.push_back({start, end});
            
            if(firstList[i][1] <= secondList[j][1])
                i++;
            else
                j++;
        }

        return ans;
    }
};