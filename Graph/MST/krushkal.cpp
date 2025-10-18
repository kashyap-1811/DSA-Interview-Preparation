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

class DisjointSet{
    public:

    int n;
    vector<int>parent;
    vector<int>rank;

    explicit DisjointSet(int n)
    {
        this->n = n;
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x)
    {
        if(parent[x] == x)
            return x;
        
        return  find(parent[x]);//path compression
    }

    void unionByRank(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);


        if(rank[parA] == rank[parB])
        {
            parent[parB] = parA;
            rank[parA]++; 
        }
        else if(rank[parA] > rank[parB])
        {
            parent[parB] = parA;
        }
        else
        {
            parent[parA] = parB;
        }
        // cout<<a<<" : "<<rank[parA]<<"           "<<b<<" : "<<rank[parB]<<" "<<endl;

    }
};

class Graph{   //connected, non-directed, weighted Graph
    int V;
    vector<Edge>E;

    public:
    explicit Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int start, int end, int weight)
    {
        int i;
        for(i=0; i< E.size(); i++)
        {
            if(E[i].wt > weight)
                break;
        }
       E.insert(E.begin()+i,Edge(start,end,weight));
    }

    void printEdgeList()
    {
        cout<<"Printing Sorted Edge List"<<endl;
        for(Edge e : E)
        {
            cout<<e.start<<" "<<e.end<<" "<<e.wt<<endl;
        }
        cout<<endl;
    }

    void KrushkalAlgo()
    {
        /* 
            sorting of a edge list
            sort(E.begin(), E.end(), [](E &a, E&b){return a.wt < b.wt});
            lambda function
        */
        int cost = 0;
        vector<Edge>MST;
        DisjointSet dj(V);

        int count = 0;
        for(Edge e : E)
        {
            int src = e.start;
            int des = e.end;
            int wt = e.wt;

            if(dj.find(src) != dj.find(des)) //current edge do not form the cycle
            {
                dj.unionByRank(src,des);
                cost += wt;
                MST.push_back(Edge(src,des,wt));
                count++;
            }

            if(count == V-1)//because in MST for V nodes total edges are V-1
                break;
        }

        cout<<"Total cost: "<<cost<<endl;
        for(Edge e : MST)
        {
            cout<<e.start<<"->"<<e.end<<" weight = "<<e.wt<<endl;
        }
    }
};

int main()
{
    //Krushkal's Algorithm
    Graph g(4);
    g.addEdge(1,3,40);//start,end,weight
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(2,3,50);
    g.addEdge(0,1,10);

    // Graph graph(7); // 7 vertices

    // // Add edges for the given test case
    // graph.addEdge(0, 1, 10);
    // graph.addEdge(0, 2, 6);
    // graph.addEdge(0, 3, 5);
    // graph.addEdge(1, 2, 5);
    // graph.addEdge(1, 4, 7);
    // graph.addEdge(1, 3, 8);
    // graph.addEdge(2, 3, 4);
    // graph.addEdge(2, 4, 9);
    // graph.addEdge(3, 4, 11);
    // graph.addEdge(3, 5, 14);
    // graph.addEdge(4, 5, 12);
    // graph.addEdge(5, 6, 9);

    //graph.printEdgeList();
    g.KrushkalAlgo();
    return 0;
}