// leet - 1711
// https://leetcode.com/problems/count-good-meals/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int> pow2;
        pow2.push_back(1);
        for (int i = 1; i <= 21; i++)
            pow2.push_back(pow2.back() * 2);

        map<int, int> m;
        long long ans = 0;
        for (int x : deliciousness) {
            for (int i : pow2) {
                if (m.count(i - x))
                    ans += m[i - x];
            }
            m[x]++;
        }

        return ans % (int)(1e9 + 7);
    }
};