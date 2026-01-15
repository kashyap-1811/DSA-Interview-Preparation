// leet - 2049
// https://leetcode.com/problems/count-nodes-with-the-highest-score/description/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<pair<int, int>>> vec(n, vector<pair<int, int>>(2, {-1, 0}));

        vector<int> NonLeaf(n, 0);
        for(int i=1; i<n; i++)
            NonLeaf[parents[i]]++;
        
        for(int i=0; i<n; i++){
            if(NonLeaf[i] == 0){
                int x = i;
                for(int parI = parents[x]; parI != -1; parI = parents[parI]){
                    if(vec[parI][0].first == -1 || vec[parI][0].first == x){
                        vec[parI][0].first = x;
                        vec[parI][0].second = vec[x][0].second + vec[x][1].second + 1;
                    }else if(vec[parI][1].first == -1 || vec[parI][1].first == x){
                        vec[parI][1].first = x;
                        vec[parI][1].second = vec[x][0].second + vec[x][1].second + 1;
                    }
                    x = parI;
                }
            }
        }

        long long maxScore = 0;
        int nodes = 0;

        for(int i=0; i<n; i++){
            int leftNodes = vec[i][0].second;
            int rightNodes = vec[i][1].second;

            long long score = 1LL * max(leftNodes, 1) * max(rightNodes, 1) * max(n-1-leftNodes-rightNodes, 1);
            // cout << i << " " << leftNodes << " " << rightNodes <<  " " << score << endl;

            if(maxScore == score)
                nodes++;
            else if(maxScore < score){
                maxScore = score;
                nodes = 1;
            }
        }

        return nodes;
    }
};