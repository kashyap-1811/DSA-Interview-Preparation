#include <bits/stdc++.h>

using namespace std;

int maxActivities(vector<vector<int>>&events)
{
    sort(events.begin(), events.end(), [](const vector<int>&a, const vector<int>&b){
        return a[1] < b[1];
    });

    for(int i=0; i<events.size(); i++)
        cout<<events[i][0]<<" "<<events[i][1]<<endl;

    int count = 1;
    int currEvent = 0;

    for(int i=1; i<events.size(); i++)
    {
        if(events[currEvent][1] <= events[i][0])  //check for non-overlapping
        {
            currEvent = i;
            count++;
        }
    }

    return count;
}

int main()
{
    vector<vector<int>>events = {{1,2}, {8,9}, {0,6}, {3,4}, {5,7}, {5,9}};

    cout<<maxActivities(events)<<endl;
    return 0;
}