// highest element with <= x
#include <bits/stdc++.h>
using namespace std;

pair<int, int> floorCeil(vector<int> &nums, int x)
{
    int start = 0, end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    
    while(start <= end){
        mid = start + (end - start) / 2;
        
        if(nums[mid] == x)
            break;
        else if(nums[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    pair<int, int> ans = {-1, -1};

    if(start <= end)
        ans = {nums[mid], nums[mid]};
    else{
        if(end >= 0)
            ans.first = nums[end];
        if(start < nums.size())
            ans.second = nums[start];
    }

    return ans;
}
 
int main()
{
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 9;

    pair<int, int> p = floorCeil(nums, x);
    cout << p.first << " " << p.second << endl;
    return 0;
}