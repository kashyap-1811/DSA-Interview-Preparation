// leet - 1423
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
        int maxSum = sum;

        for(int i=n-1; i>=(n-k); i--){
            sum -= cardPoints[k-n+i];
            sum += cardPoints[i];

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};