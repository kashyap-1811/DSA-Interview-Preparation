// leet - 121
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        vector<int>buy(prices);

        for(int i=1; i<buy.size(); i++)
            buy[i] = min(prices[i], buy[i-1]);

        for(int i=0; i<prices.size(); i++)
            if(maxProf < prices[i] - buy[i])
                maxProf = prices[i] - buy[i];

        return maxProf;
    }
};