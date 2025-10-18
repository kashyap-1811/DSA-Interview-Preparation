#include<bits/stdc++.h>
using namespace std;

void SOS(vector<int>&nums, int idx, int target, int curr, int rem, vector<int>&path, vector<vector<int>>&res){
    cout<<"SOS("<<curr<<", "<<idx+1<<", "<<rem<<")"<<endl;
    //include
    path[idx] = 1;
    if(curr + nums[idx] == target){
        res.push_back(path);
        return;
    }
    else if(curr + nums[idx] + nums[idx+1] <= target){
        SOS(nums, idx+1, target, curr+nums[idx], rem-nums[idx], path, res);
    }

    //exclude
    if(curr+rem-nums[idx]>=target && curr+nums[idx+1]<=target){
        path[idx] = 0;
        SOS(nums, idx+1, target, curr, rem-nums[idx], path, res);
    }
}

int main()
{
    vector<int>nums = {1, 2, 5, 8, 10};
    int target = 10;
    vector<int>path(nums.size(), 0);
    vector<vector<int>>res;

    int rem = accumulate(nums.begin(), nums.end(), 0);

    SOS(nums, 0, target, 0, rem, path, res);

    // for(int i=0; i<res.size(); i++){
    //     for(int j=0; j<res[i].size(); j++){
    //         if(res[i][j] == 1)
    //             cout<<nums[j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}