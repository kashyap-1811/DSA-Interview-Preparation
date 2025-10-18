#include <bits/stdc++.h>

using namespace std;

void NextGreater(vector<int>nums, vector<int>&ans)
{
    stack<int>s;
    ans.at(ans.size()-1)=-1;
    s.push(ans.size()-1);

    for(int i=ans.size()-2; i>-1; i--)
    {
        while(!s.empty() && nums[i]>nums[s.top()])
        {
            s.pop();
        }

        if(s.empty())
        {
            ans.at(i)=-1;
        }
        else
        {
            ans.at(i)=nums.at(s.top());
        }
        s.push(i);
    }
}

int main()
{
    vector<int>nums={6,8,0,1,3};
    vector<int>ans(5);

    NextGreater(nums,ans);

    for(int i=0;i<ans.size();i++)
        cout<<ans.at(i)<<" ";
    return 0;
}