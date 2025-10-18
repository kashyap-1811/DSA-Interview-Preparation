#include <bits/stdc++.h>
using namespace std;

int helper(int i, vector<int>& heights, vector<int>& dp, int& n){
    if(i == n-1)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int one = INT_MAX;
    if(i+1 < n)
        one = helper(i+1, heights, dp, n) + abs(heights[i] - heights[i+1]);

    int two = INT_MAX;
    if(i+2 < n)
        two = helper(i+2, heights, dp, n) + abs(heights[i] - heights[i+2]);

    return dp[i] = min(one, two);
}

int FrogJump(vector<int>& heights){
    int n = heights.size();
    vector<int> dp(n, -1);
    return helper(0, heights, dp, n);
}

int main(){
    vector<int> heights = {
        10, 30, 40, 20, 25, 50, 10, 60, 70, 20, 25, 30, 60, 55, 75, 90, 65, 35, 30, 10,
        20, 45, 70, 20, 80, 40, 60, 10, 90, 85, 50, 35, 25, 45, 65, 85, 20, 15, 30, 45,
        70, 95, 85, 60, 40, 20, 10, 5, 0, 10, 20, 30, 50, 70, 90, 80, 60, 55, 65, 75,
        85, 95, 100, 80, 60, 40, 20, 10, 0, 25, 50, 75, 100, 90, 85, 70, 55, 40, 30, 20,
        15, 10, 5, 2, 0, 1, 3, 6, 10, 20, 25, 30, 35, 40, 45, 50, 52, 55, 60, 62
    };
    cout << FrogJump(heights) << endl;
    return 0;
}
