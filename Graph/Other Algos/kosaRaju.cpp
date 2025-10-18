#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
    int V;
    list<int>*l;

    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }

    void DFS(int src, vector<bool>&vis, stack<int>&s)
    {
        vis[src] = true;
        cout<<src<<" ";

        list<int>neighbours = l[src];
        for(int v : neighbours)
        {
            if(vis[v] == false)
            {
                DFS(v, vis, s);
            }
        }

        s.push(src);
    }

    void gTranspose()
    {
        list<int>*gt = new list<int>[V];

        for(int i=1; i<V; i++)
        {
            for(int v : l[i])
            {
                gt[v].push_back(i);
            }
        }

        this->l = gt;

        for(int i=1; i<V; i++)
        {
            cout<<i<<" : ";
            for(int v : l[i])
            {
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    void kosaraju()
    {
        stack<int>s, tmp;
        vector<bool>vis(V, false);

        DFS(1, vis, s);
        cout<<endl;
        gTranspose();

        for(int i=0; i<V; i++)
            vis[i] = false;

        int counter = 0;
        cout<<endl<<"SCC are: "<<endl;
        while(!s.empty())
        {
            int u = s.top();
            s.pop();
            if(vis[u] == false)
            {
                cout<<"SCC: "<<(++counter)<<" : ";
                DFS(u, vis, tmp);
                cout<<endl;
            }
        }
    }
};

int main()
{
    Graph g(9);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(6,5);
    g.addEdge(6,7);
    g.addEdge(7,8);

    g.kosaraju();
    return 0;
}