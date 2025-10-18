#include <bits/stdc++.h>
using namespace std;

void nextValue(vector<vector<int>>& graph, int k, vector<int>& sol, int v, vector<bool>& vis) {
    while (true) {
        sol[k] = (sol[k] + 1) % v; // Try next vertex in a cyclic manner

        if (sol[k] == 0) // If it cycles back to 0, return (invalid choice)
            return;

        if (graph[sol[k - 1]][sol[k]] != 0 && !vis[sol[k]]) { // Check connectivity & visited status
            vis[sol[k]] = true;
            return;
        }
    }
}

void Hamiltonian_cycle(vector<vector<int>>& graph, int k, vector<int>& sol, int v, vector<bool>& vis, int &price, vector<int>&ans) {
    if (k == v) { // If all vertices are visited
        if (graph[sol[k - 1]][sol[0]] != 0) { // Check if last vertex connects to first
            int curr = 0;
            for (int i = 0; i < v; i++)
                curr += graph[sol[i]][sol[(i + 1) % v]]; // Calculate the total cost

            if (curr < price){
                price = curr;
                ans = sol;
            }
        }
        return;
    }

    while (true) {
        nextValue(graph, k, sol, v, vis);
        if (sol[k] == 0) // If no valid move, return
            return;

        Hamiltonian_cycle(graph, k + 1, sol, v, vis, price, ans);
        vis[sol[k]] = false; // Backtracking step to explore other paths
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 8, 3, 5},
        {6, 0, 4, 3},
        {3, 4, 0, 10},
        {5, 3, 9, 0}
    };

    int v = graph.size();
    vector<int> sol(v, 0);
    vector<bool> vis(v, false);

    sol[0] = 0; // Start at node 0
    vis[0] = true;
    int price = INT_MAX;
    vector<int>ans(v, 0);

    Hamiltonian_cycle(graph, 1, sol, v, vis, price, ans);
    cout << price << endl;

    for(int i=0; i<v; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}