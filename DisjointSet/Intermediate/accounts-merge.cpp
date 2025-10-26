// leet - 721
// https://leetcode.com/problems/accounts-merge/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(string x, string y) {
        parent[find(x)] = find(y);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;

        // Step 1: Initialize parent and email-to-name map
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                parent[account[i]] = account[i];
                emailToName[account[i]] = name;
            }
        }

        // Step 2: Union emails in the same account
        for (auto& account : accounts) {
            string firstEmail = account[1];
            for (int i = 2; i < account.size(); i++) {
                unite(account[i], firstEmail);
            }
        }

        // Step 3: Group emails by their root parent
        unordered_map<string, set<string>> unions;
        for (auto& [email, _] : emailToName) {
            string root = find(email);
            unions[root].insert(email);
        }

        // Step 4: Build result
        vector<vector<string>> res;
        for (auto& [root, emails] : unions) {
            vector<string> group;
            group.push_back(emailToName[root]);
            group.insert(group.end(), emails.begin(), emails.end());
            res.push_back(group);
        }

        return res;
    }
};
