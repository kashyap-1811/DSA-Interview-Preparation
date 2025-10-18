#include <bits/stdc++.h>

using namespace std;

bool targetSum(vector<int>&nums, int &target)
{
    vector<vector<int>>dp(nums.size()+1, vector<int>(target+1, 0));

    for(int i=1; i<=nums.size(); i++)
    {
        for(int j=1; j<=target; j++)
        {
            //include
            int take = 0;
            if(nums[i-1] <= j)
                take = nums[i-1] + dp[i-1][j-nums[i-1]];

            //exclude
            int not_take = dp[i-1][j];

            dp[i][j] = max(take, not_take);
        }
    }

    for(int i=1; i<=nums.size(); i++)
    {
        for(int j=1; j<=target; j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    return dp[nums.size()][target] == target;
}

int main()
{
    vector<int>nums = {1, 2, 3, 7, 9, 10, 11};
    int target = 10;

    cout<<targetSum(nums, target)<<endl;
    return 0;
}