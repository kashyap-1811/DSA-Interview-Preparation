// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
  public:
    bool isOverlap(int a, int b) {
        // new train arrival
        int arrMin = b % 100;
        b /= 100;
        int arrHr = b;
        
        // first train dep
        int depMin = a % 100;
        a /= 100;
        int depHr = a;
        
        if(arrHr < depHr || arrHr == depHr && arrMin <= depMin)
            return true;
        return false;
    }
    
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<vector<int>> nums;
        
        for(int i=0; i<arr.size(); i++) {
            nums.push_back({arr[i], dep[i]});
        } 
        
        sort(nums.begin(), nums.end());
        priority_queue<int, vector<int>, greater<>> pq; // min heap
        
        
        int ans = 1;
        pq.push(nums[0][1]);
        
        for(int r=1; r<nums.size(); r++) {
            while(!pq.empty() && !isOverlap(pq.top(), nums[r][0]))
                pq.pop();
                
            pq.push(nums[r][1]);
            
            ans = max(ans, (int)pq.size());
        }
        
        return ans;
    }
};
