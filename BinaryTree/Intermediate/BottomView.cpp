// leet - 
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
 
#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
  
    void traverse(Node *root, map<int, pair<int, int>> &m, int row, int col){
        if(root == nullptr)
            return;
        
        if(!m.count(col) || m[col].first <= row)
            m[col] = {row, root->data};
        traverse(root->left, m, row+1, col-1);
        traverse(root->right, m, row+1, col+1);
    }
    
    vector<int> bottomView(Node *root) {
        // code here
        map<int, pair<int, int>> m;
        traverse(root, m, 0, 0);
        
        vector<int> ans;
        for(auto [_, x] : m)
            ans.push_back(x.second);
        return ans;
    }
};