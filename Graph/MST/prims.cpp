#include <bits/stdc++.h>

using namespace std;

class Edge{
    public:
    int start;
    int end;
    int wt;

    Edge(int start, int end, int wt)
    {
        this->start = start;
        this->end = end;
        this->wt = wt;
    }
};

class Graph{
    int V;
    list<pair<int,int>> *l; //pair stores end vertex and the weight

    public:
    Graph(int V)
    {
        this->V = V;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int start, int end, int weight)
    {
        l[start].push_back(make_pair(end,weight));
        l[end].push_back(make_pair(start,weight));
    }

    void primsAlgo(int src)
    {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq; //(wt,(u,v))
        pq.push(make_pair(0,make_pair(0,0))); //pq is of type min heap

        vector<bool>mst(V,false);
        int cost = 0;

        vector<Edge>E;

        while(pq.size() > 0)
        {
            int u = pq.top().second.first; //taking source vertex out from pq: u from(u,v)
            int v = pq.top().second.second; //taking destination vertex out from pq: v from(u,v)
            int wt = pq.top().first;
            pq.pop();

            if(!mst[v])
            {
                mst[v] = true;
                cost += wt;
                
                if(u != v) //to skip first default initialization of pq as (0,(0,0))
                    E.push_back(Edge(u,v,wt));

                list<pair<int,int>>neighbours = l[v];
                for(pair<int,int>n : neighbours)
                {
                   pq.push(make_pair(n.second,make_pair(u,n.first))); //n.second = wt, n.first = vertex, u = parent 
                }
            }
        }

        cout<<"Total Cost of MST: "<<cost<<endl;

        cout<<"Printing all edges: "<<endl;
        for(Edge e : E)
        {
            cout<<e.start<<"->"<<e.end<<" weight "<<e.wt<<endl;
        }
    }
};

int main()
{
    //prims's Algorithm
    Graph g(4);
    g.addEdge(0,1,10);//start,end,weight
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(1,3,40);
    g.addEdge(2,3,50);

    g.primsAlgo(0);
    return 0;
}