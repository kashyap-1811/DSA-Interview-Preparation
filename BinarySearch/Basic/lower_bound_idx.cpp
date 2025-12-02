#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &nums, int x)
{
    int start = 0, end = nums.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    
    while(start <= end){
        mid = start + (end - start) / 2;

        if(nums[mid] >= x)
            ans = mid;
        
        if(nums[mid] >= x)
            end = mid - 1;
        else
            start = mid + 1;
    }
    
    return ans != -1 ? nums[ans] : -1;
}
 
int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,14,19,23,25,45};
    int x = 111;

    cout << lower_bound(nums, x);
    return 0;
}