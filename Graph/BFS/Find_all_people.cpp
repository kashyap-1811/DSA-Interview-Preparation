// leet - 2092
// https://leetcode.com/problems/find-all-people-with-secret/description/?envType=daily-question&envId=2025-12-18
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;

        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            unordered_map<int, vector<int>> graph;
            vector<int> people;

            // collect same-time meetings
            while (i < meetings.size() && meetings[i][2] == time) {
                int x = meetings[i][0], y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.push_back(x);
                people.push_back(y);
                i++;
            }

            unordered_set<int> visited;

            for (int p : people) {
                if (visited.count(p)) continue;

                // BFS component
                queue<int> q;
                vector<int> component;
                q.push(p);
                visited.insert(p);

                bool hasSecret = knows[p];

                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    component.push_back(u);
                    for (int v : graph[u]) {
                        if (!visited.count(v)) {
                            visited.insert(v);
                            q.push(v);
                            if (knows[v]) hasSecret = true;
                        }
                    }
                }

                if (hasSecret) {
                    for (int v : component)
                        knows[v] = true;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (knows[i]) ans.push_back(i);

        return ans;
    }
};
