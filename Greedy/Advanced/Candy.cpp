// leet - 135
// https://leetcode.com/problems/candy/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 0), right(n, 0);

        left[0] = 1;
        right[n-1] = 1;
        for(int i=1, j=n-2; i<ratings.size(); i++, j--){
            if(ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
            else
                left[i] = 1;
            
            if(ratings[j] > ratings[j+1])
                right[j] = right[j+1] + 1;
            else
                right[j] = 1;
        }

        int count = 0;
        for(int i=0; i<n; i++)
            count += max(left[i], right[i]);
        
        return count;
    }
};