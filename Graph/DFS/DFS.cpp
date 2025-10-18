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

    void DFS(int u, vector<bool>&visited) //O(V + E)
    {
        visited[u] = true;
        cout<<u<<" ";

        list<int>neighbours = l[u];
        for(int i : neighbours)
        {
            if(!visited[i])
                DFS(i,visited);
        }
    }

    void DFS_iterative()
    {
        cout<<"DI"<<endl;
        stack<int>s;
        vector<bool>vis(V,false);
        vis[0] = true;
        s.push(0);

        while(!s.empty())
        {
            int n = s.top();  s.pop();
            vis[n] = true;
            cout<<n<<" ";

            for(auto v : l[n]){
                if(!vis[v]){
                    vis[v] = true;
                    s.push(v);
                }
            }
        }
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

    //g.print();

    vector<bool>visited(7,false);
    g.DFS(0,visited);
    g.DFS_iterative();

    return 0;
}