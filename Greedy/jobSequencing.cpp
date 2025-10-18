#include <bits/stdc++.h>

using namespace std;

class job{
    public:
    int id;
    int deadline;
    int profit;

    job(): id(0), deadline(0), profit(0){}
    job(int id, int deadline, int profit):id(id), deadline(deadline), profit(profit){}
};

class Disjoint{
    public:
    int n;
    vector<int>parent;

    Disjoint(int n)
    {
        this->n = n;
        for(int i=0; i<n; i++)
            parent.push_back(i);
    }

    int find(int x)
    {
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v)
    {
        parent[v] = u;
    }
};

int maxdeadline(vector<int>&deadline)
{
    int max = deadline[0];
    for(int i : deadline)
        if(max < i)
            max = i;

    return max;
}

vector<int> jobSequencing(vector<int>&id, vector<int>&deadline, vector<int>&profit)
{
    int n = id.size();
    vector<job>j;
    for(int i=0; i<n; i++)
        j.emplace_back(id[i], deadline[i], profit[i]);

    sort(j.begin(), j.end(), [](const job &a, const job &b){
        return a.profit > b.profit;
    });

    int no_of_slots = min(n, maxdeadline(deadline));
    Disjoint dj(no_of_slots+1);

    int countJobs = 0;
    int pro = 0;
    for(int i=0; i<n; i++)
    {
        int availableSlot = dj.find(min(n, j[i].deadline));
        if(availableSlot > 0)
        {
            cout<<j[i].id<<" "<<j[i].profit<<endl;
            pro += j[i].profit;
            countJobs++;
            dj.unite(dj.find(availableSlot-1), availableSlot);   
        }
    }

    return vector<int>{countJobs, pro};
}

int main()
{
    //id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
    vector<int>id = {1, 2, 3, 4};
    vector<int>deadline = {4, 1, 1, 1};
    vector<int>profit = {20, 1, 40, 30};

    vector<int> ans = jobSequencing(id, deadline, profit);

    cout<<"ans: "<<ans[0] <<" "<<ans[1]<<endl;
    return 0;
}