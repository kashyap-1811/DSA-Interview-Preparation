// leet - 2076
// https://leetcode.com/problems/process-restricted-friend-requests/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> parent;

    int find(int g){
        if(g == parent[g])
            return g;
        return parent[g] = find(parent[g]);
    }

    void unite(int g1, int g2){
        int parG1 = find(g1);
        int parG2 = find(g2);

        parent[parG2] = parG1;
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        int Id = -1;
        unordered_map<int, int> findGroup; // personId -> groupId

        for(auto &r : requests){
            int p1 = r[0], p2 = r[1];
            bool canBeFriends = true;

            int gp1 = -1, gp2 = -1; // gp(i) -> group of person i
            if(findGroup.count(p1))
                gp1 = find(findGroup[p1]);
            if(findGroup.count(p2))
                gp2 = find(findGroup[p2]);

            // check all restrictions: Direct or indirect
            for(auto &res : restrictions){
                int r1 = res[0], r2 = res[1];
                int rg1 = -1, rg2 = -1;
                if(findGroup.count(r1))
                    rg1 = find(findGroup[r1]);
                if(findGroup.count(r2))
                    rg2 = find(findGroup[r2]);

                if(pair(min(p1, p2), max(p1, p2)) == pair(min(r1, r2), max(r1, r2))){
                    canBeFriends = false;
                    break;
                }else if(gp1 != -1 && gp2 != -1){
                    if(pair(min(gp1, gp2), max(gp1, gp2)) == pair(min(rg1, rg2), max(rg1, rg2))){
                        canBeFriends = false;
                        break;
                    }
                }else if(gp1 != -1){
                    if((gp1 == rg1 || gp1 == rg2) && (p2 == r1 || p2 == r2)){
                        canBeFriends = false;
                        break;
                    }
                }else if(gp2 != -1){
                    if((gp2 == rg1 || gp2 == rg2) && (p1 == r1 || p1 == r2)){
                        canBeFriends = false;
                        break;
                    }
                }
            }

            // create or unite groups
            if(canBeFriends){
                if(gp1 == -1 && gp2 == -1){
                    Id++;
                    findGroup[p1] = Id;
                    findGroup[p2] = Id;
                    parent.push_back(Id);
                }else if(gp1 == -1)
                    findGroup[p1] = gp2;
                else if(gp2 == -1)
                    findGroup[p2] = gp1;
                else
                    unite(gp1, gp2);
            }

            // insert the answer of query
            ans.push_back(canBeFriends);
        }

        return ans;
    }
};