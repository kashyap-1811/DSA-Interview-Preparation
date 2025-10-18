//Directed Acyclic Grpah
// Linear Order of vertices such that for every u->v
//      u comes before v in sequence
#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    Graph operator=(const Graph &g)
    {
        this->V = g.V;
        l = new list<int>[V];

        for(int i=0;i<V;i++)
        {
            l[i] = g.l[i];
        }

        return *this;
    }

    Graph(const Graph &g)
    {
        this->V = g.V;
        l = new list<int>[V];

        for(int i=0;i<V;i++)
        {
            l[i] = g.l[i];
        }
    }

    void addEdge(int start, int end){
        l[start].push_back(end);
    }

    void inDegree(vector<int>&indeg)
    {
        for(int i=0;i<V;i++)
        {
            for(auto v : l[i])
                indeg[v]++;
        }
    }

    bool Kahn_topo_sort()
    {
        vector<int>indeg(V,0);
        inDegree(indeg);

        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indeg[i] == 0)
                q.push(i);
        }

        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";
            for(auto v : l[curr])
            {
                indeg[v]--;
                if(indeg[v] == 0)
                    q.push(v);
            }
        }
        cout<<endl;

        for(int i=0;i<V;i++)
        {
            if(indeg[i])
                return true;
        }

        return false;
    }
    
};

int main()
{
    Graph g(6);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(1,4);

    cout<<g.Kahn_topo_sort();
    return 0;
}