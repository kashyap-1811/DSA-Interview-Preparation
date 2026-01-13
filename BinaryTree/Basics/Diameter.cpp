// leet - 543
// https://leetcode.com/problems/diameter-of-binary-tree/
 
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
    int traverse(TreeNode *root, int &maxDist){
        if(root == nullptr)
            return 0;
        
        int left = traverse(root->left, maxDist);
        int right = traverse(root->right, maxDist);

        maxDist = max(maxDist, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDist = 0;
        traverse(root, maxDist);
        return maxDist;
    }
};