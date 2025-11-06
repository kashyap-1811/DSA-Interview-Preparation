// leet - 122
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution { // greedy
public:
    int maxProfit(vector<int>& p) {
        int res = 0;
        for (int i = 1; i < p.size(); i++)
            if (p[i - 1] <= p[i])
                res += p[i] - p[i - 1];
        return res;
    }
};

// class Solution {  //  dp
// public:

//     int f(vector<int>& p, bool holding, int i , vector<vector<int> > &dp) {
//         if (i == p.size()) return 0;
//         if (dp[i][holding] != -1) return dp[i][holding];
//         if (holding == false) {
//             int buy = f(p, true, i + 1 , dp) - p[i];
//             int skip = f(p, false, i + 1 , dp);
//             return  dp[i][holding] = max(buy, skip);
//         } else {
//             int sell = f(p, false, i + 1 , dp) + p[i];
//             int skip = f( p, true, i + 1 , dp );
//             return dp[i][holding]= max(sell, skip);
//         }
//     }

//     int maxProfit(vector<int>& p) {
//         vector<vector<int>>dp(p.size()+1 , vector<int>(2 , -1) );
//         return f(p , false , 0 , dp);
//     }
// };