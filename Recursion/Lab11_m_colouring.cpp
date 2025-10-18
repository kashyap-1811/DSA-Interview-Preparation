#include<bits/stdc++.h>
using namespace std;

void nextValue(vector<vector<int>>&adj, int k, vector<int>&sol, int m, int v)
{
    while(true)
    {
        sol[k] = (sol[k] + 1) % (m+1);
        if(sol[k] == 0)
            return;

        bool check = true;
        vector<int>nei = adj[k];

        for(int i=0; i<nei.size(); i++)
        {
            if(sol[nei[i]] == sol[k])
            {
                check = false;
                break;
            }
        }

        if(check == true)
            return;
    }
}

void m_colouring(vector<vector<int>>&adj, int k, vector<int>&sol, int m, int v)
{
    while(true)
    {
        nextValue(adj, k, sol, m, v);
        if(sol[k] == 0)
            return;

        if(k == v-1)
        {
            for(int i=0; i<v; i++)
                cout<<sol[i]<<" ";
            cout<<endl;
        }
        else
        {
            m_colouring(adj, k+1, sol, m, v);
        }
    }
}


int main()
{
    vector<vector<int>>adj = {
                                {1, 2, 3},
                                {0, 2},
                                {0, 1, 3},
                                {0, 2}
                            };
    int m = 3;
    int v = 4;

    vector<int>sol(v, 0);
    m_colouring(adj, 0, sol, m, v);

    return 0;
}