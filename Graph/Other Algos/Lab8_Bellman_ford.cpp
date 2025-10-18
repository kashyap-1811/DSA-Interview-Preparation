#include <bits/stdc++.h> //negative weighted graph  //DP algorithm

using namespace std;

class Edge{
    public:
    int des;
    int wt;

    Edge(int des, int wt)
    {
        this->des = des;
        this->wt = wt;
    }
};

void Bellman_Ford_Algo(int src, const vector<vector<Edge>>&g, int V) //O(V.E)
{
    vector<int>dist(V,INT_MAX);
    dist[src] = 0;

    for(int i=0;i<V-1;i++)
    {
        for(int u=0;u<V;u++)
        {
            for(Edge e : g[u]){
                if(dist[u]!=INT_MAX && dist[e.des] > dist[u] + e.wt)  //Edge Relaxation
                    dist[e.des] = dist[u] + e.wt;
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < V; u++) {
        for (Edge e : g[u]) {
            if (dist[u] != INT_MAX && dist[e.des] > dist[u] + e.wt) {
                cout << "Graph contains a negative weight cycle." << endl;
                return;
            }
        }
    }

    for(int d : dist)
    {
        cout<<d<<" ";
    }

    cout<<endl;
}


/* we traverse V-1 times to ensure that even the longest path is covered

   BF Algo doesn't work for negative Weight cycles 
   (because the cycle finds the shortest distance infinite times)   
*/

int main()
{
    int V = 5;
    vector<vector<Edge>>g(V);

    g[0].push_back(Edge(1,6));  //Edge(1->des, 2->wt)
    g[0].push_back(Edge(3,7));

    g[1].push_back(Edge(2,5));
    g[1].push_back(Edge(3,8));

    g[2].push_back(Edge(1,-2));

    g[3].push_back(Edge(2,-3));
    g[3].push_back(Edge(4,9));

    g[4].push_back(Edge(0,-2));
    g[4].push_back(Edge(2,7));

    Bellman_Ford_Algo(0, g, V);
    return 0;
}