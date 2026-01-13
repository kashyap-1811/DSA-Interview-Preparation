// leet - 987
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 
#include <bits/stdc++.h>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    void traverse(TreeNode *root, map<int, map<int, vector<int>>> &m, int row, int col){
        if(root == nullptr)
            return;
        
        m[col][row].push_back(root->val);
        traverse(root->left, m, row+1, col-1);
        traverse(root->right, m, row+1, col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> m;
        traverse(root, m, 0, 0);

        vector<vector<int>> ans;
        for(auto [_, M] : m){
            vector<int> temp;

            for(auto [__, vec] : M){
                sort(vec.begin(), vec.end());
                for(auto &i : vec)
                    temp.push_back(i);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};