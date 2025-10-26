// leet - 737
// https://leetcode.com/problems/sentence-similarity-ii/
 
#include <bits/stdc++.h>
using namespace std;
 
// u: 2
class Solution {
public:
    unordered_map<string, string> parent;

    string find(string &x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(string &a, string &b){
        string parA = find(a);
        string parB = find(b);

        parent[parA] = parB;
    }

    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        // check for length condition
        if(sentence1.size() != sentence2.size())    
            return false;
        
        // need to create disjoint sets
        for(auto &p : similarPairs){
            if(!parent.count(p[0]))
                parent[p[0]] = p[0];
            if(!parent.count(p[1]))
                parent[p[1]] = p[1];
            unite(p[0], p[1]);
        }
        
        // comparing elements
        for(int i=0; i<sentence1.size(); i++){
            string  &word1 = sentence1[i],
                    &word2 = sentence2[i];
            
            if(word1 == word2)
                continue;
            if(parent.count(word1) && parent.count(word2) && find(word1) == find(word2))
                continue;
            return false;  
        }
        
        return true;
    }
};