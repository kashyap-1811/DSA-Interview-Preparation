#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> *l; //for weighted graph--> list<pair<int,int>>*l;
    public:

    explicit Graph(int V)
    {
        this->V = V;
        this->l = new list<int>[V];
    }

    Graph(const Graph &g)
    {
        this->V = g.V;
        for(int i=0; i<V; i++)
            this->l[i] = g.l[i];
    }

    Graph operator= (const Graph &g)
    {
        this->V = g.V;
        if(l != nullptr)
            delete []l;

        for(int i=0; i<V; i++)
            this->l[i] = g.l[i];

        return *this;
    }

    void addEdge(int startNode, int endNode) //startNode ---- endNode
    {
        l[startNode].push_back(endNode);
        l[endNode].push_back(startNode);
    }

    void print()
    {
        for(int start=0;start<V;start++)
        {
            cout<<"Start Node: "<<start<<": ";
            list<int>neighbours = l[start];
            for(int V : neighbours)
                cout<<V<<" ";
            cout<<endl;
        }
    }

    void BFS() //O(V + E)
    {
        queue<int>q;
        vector<bool>vis(V,false);
        q.push(0);
        vis[0] = true;

        while(q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            list<int>neighbous = l[curr];
            for(int v : neighbous)
            {
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void BFS_helper(queue<int>&q, vector<bool>&vis)
    {
        if(q.empty())  return;
        
        int u = q.front(); q.pop();
        vis[u] = true;
        cout<<u<<" ";

        list<int>neighbours = l[u];
        for(auto v : neighbours){
            if(!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }

        BFS_helper(q,vis);
    }

    void BFS_recursion(int start)
    {
        vector<bool>vis(V,false);
        queue<int>q;
        q.push(start);

        BFS_helper(q,vis);
    }
};

int main()
{
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);

    g.print();
    g.BFS();cout<<endl;
    g.BFS_recursion(0);

    return 0;
}