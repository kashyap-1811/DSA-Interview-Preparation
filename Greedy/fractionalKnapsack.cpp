#include <bits/stdc++.h>

using namespace std;

double fractionalknapsack(vector<int>&val, vector<int>&wt, int &capacity)
{
    //https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/0
    priority_queue<pair<double, int>>pq;
    for(int i=0; i<val.size(); i++)
        pq.push({(double)val[i]/wt[i], i});

    double sum = 0;
    while(pq.size())
    {
        if(capacity >= wt[pq.top().second])
        {
            sum += val[pq.top().second];
            capacity -= wt[pq.top().second];
        }
        else
        {
            sum +=((double)val[pq.top().second]/wt[pq.top().second])*capacity;
            capacity = 0;
            return sum;
        }

        pq.pop();
    }

    return sum;
}

int main()
{
    vector<int>value = {60, 100, 120};
    vector<int>weight = {10, 20, 30};
    int capacity = 50;

    cout<<fractionalknapsack(value, weight, capacity)<<endl;
    return 0;
}