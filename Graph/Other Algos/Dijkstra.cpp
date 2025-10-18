#include <bits/stdc++.h>  //non-negative weighted graph //Greedy Algorithm

using namespace std;

class  Edge{
    public:
    int des;
    int wt;

    Edge(int des, int wt)
    {
        this->des = des;
        this->wt = wt;
    }
};

void DijkstraAlgo(int src, const vector<vector<Edge>>&g, int V)  //O( (V+E)logV )
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; //min_heap  //pair(dist[v] , v)
    vector<int>dist(V,INT_MAX);

    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(pq.size() > 0)
    {
        int u = pq.top().second;
        pq.pop();

        vector<Edge>neighbours = g[u];
        for(auto e : neighbours)
        {
            if(dist[e.des] > dist[u] + e.wt){    //Edge Relaxation
                dist[e.des] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.des],e.des));
            }
        }
    }

    for(int d : dist)
    {
        cout << d << " ";
    }
    cout << endl;
}

int main()
{
    int V=6;
    vector<vector<Edge>>g(V);

    g[0].push_back(Edge(1,2)); //1->des, 2->wt
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,1));
    g[1].push_back(Edge(3,7));

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));

    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(2,5));

    DijkstraAlgo(2,g,V);
    

    return 0;
}