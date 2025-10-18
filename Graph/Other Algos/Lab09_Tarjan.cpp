#include <bits/stdc++.h>

using namespace std;

void DFS(int src, int parent, vector<vector<int>>&edges, vector<int>&low, vector<int>&dfn, int &num, vector<int>&AP,
            vector<bool>&isAP)
{
    low[src] = dfn[src] = num++;
    int children = 0;

    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0]-1;
        int v = edges[i][1]-1;

        if(u == src)
        {
            if(dfn[v] == 0)
            {
                DFS(v, u, edges, low, dfn, num, AP, isAP);
                children++;
                low[u] = min(low[u], low[v]);

                if(!isAP[u] && parent==-1 && children>1){ //for root
                    AP.push_back(u+1);
                    isAP[u] = true;
                }
                else if(!isAP[u] && parent!=-1 && low[v]>=dfn[u]) {//for internal nodes
                    AP.push_back(u+1);
                    isAP[u] = true;
                }
            }
            else if(v != parent)
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
}

void Tarjan(vector<vector<int>>&edges, int n)
{
    int num = 1;
    vector<int>low(n, INT_MAX);
    vector<int>dfn(n, 0);

    vector<int>AP;
    vector<bool>isAP(n, false);

    for (int i = 0; i < n; i++)  // Handle disconnected components
    {
        if (dfn[i] == 0) {
            DFS(i, -1, edges, low, dfn, num, AP, isAP);
        }
    }

    // for(int i=0; i<n; i++)
    // {
    //     cout<<low[i]<<" "<<dfn[i]<<endl;
    // }

    cout<<"Articulation points: ";
    if(AP.size() == 0)
        cout<<"NO APs";
    else{
        for(int i=0; i<AP.size(); i++)
            cout<<AP[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<vector<int>>edges = {
        // {1,4},{1,2},{2,1},{2,3},{2,5},{2,7},{2,8},{3,2},{3,4},{3,9},{3,10},{4,1},
        // {4,3},{5,2},{5,6},{5,7},{5,8},{7,2},{7,5},{7,8},{8,2},{8,5},{8,7},
        {1,3},{1,2},{2,1},{2,4},{3,1},{3,4},{3,5},{5,3},{4,2},{4,3},{4,6},{6,4},{6,7},{6,8},{7,6},{8,6},
    };

    Tarjan(edges, 8);
    return 0;
}