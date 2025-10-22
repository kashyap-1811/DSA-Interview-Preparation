// leet - 2115
// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool DFS(int u, vector<vector<int>> &prereq,
                    vector<int> &canBeMade, vector<bool> &rec)
    {
        rec[u] = true;

        for(int v : prereq[u]){
            if(rec[v]){
                canBeMade[u] = 0;
                return false;
            }

            if(canBeMade[v] == -1){
                if(!DFS(v, prereq, canBeMade, rec)){
                    canBeMade[u] = 0;
                    return false;
                }
            }else if(canBeMade[v] == 0){
                canBeMade[u] = 0;
                return false;
            }
        }

        rec[u] = false;
        return true;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();

        // map to store recipes
        unordered_map<string, int> recipe_map;
        for(int i=0; i<n; i++)
            recipe_map[recipes[i]] = i;
        
        // set to store supplies
        unordered_set<string> supplies_set;
        for(auto s : supplies)
            supplies_set.insert({s});

        // vector to store possible or not for any recipe
        vector<int> canBeMade(n, -1); // -1 -> not visited, 0 -> not possible, 1 -> possible
        
        // finding preReq for each other
        vector<vector<int>> prereq(n, vector<int>());
        
        // finding prereq and possible or not
        for(int i=0; i<n; i++){
            for(auto ing : ingredients[i]){
                if(recipe_map.count(ing)){
                    int idx = recipe_map[ing];
                    if(canBeMade[idx] == -1)
                        prereq[i].push_back(idx);
                    else if(canBeMade[idx] == 0){
                        canBeMade[i] = 0;
                        break;
                    }
                }else if(!supplies_set.count(ing)){
                    canBeMade[i] = 0;
                    break;
                }
            }

            if(canBeMade[i] == -1 && prereq[i].size() == 0)
                canBeMade[i] = 1;
        }

        // now dfs on prereq array
        vector<bool> rec(n, false);
        for(int i=0; i<n; i++)
            if(canBeMade[i] == -1 && DFS(i, prereq, canBeMade, rec))
                canBeMade[i] = 1;

        // last creating answer vector
        vector<string> ans;
        for(int i=0; i<n; i++)
            if(canBeMade[i] == 1)
                ans.push_back(recipes[i]);
        
        return ans;
    }
};