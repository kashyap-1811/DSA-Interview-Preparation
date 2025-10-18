// leet - 901
// https://leetcode.com/problems/online-stock-span/description/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {}
    
    int next(int price) {
        if(st.empty() || st.top().first > price)
            st.push({price, 1});
        else{
            int span = 1;
            while(!st.empty() && st.top().first <= price){
                span += st.top().second;
                st.pop();
            }
            st.push({price, span});
        }

        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */