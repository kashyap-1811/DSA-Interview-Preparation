// leet - 950
// https://leetcode.com/problems/reveal-cards-in-increasing-order/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        queue<int> q;
        vector<int> ans(n);

        for(int i=0; i<n; i++)
            q.push(i);
        int idx = 0;
        
        while(!q.empty()){
            int currIdx = q.front(); q.pop();
            ans[currIdx] = nums[idx++];

            if(!q.empty()){
                currIdx = q.front(); 
                q.pop();
                q.push(currIdx);
            }
        }

        return ans;
    }
};