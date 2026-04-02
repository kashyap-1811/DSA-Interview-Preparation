// leet - 
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description
 
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

typedef long long ll;

class Solution {
public:
    const int MOD = 1e9 + 7;

    void calculateSum(TreeNode *root, ll &totalSum){
        if(root == nullptr)
            return;
        
        totalSum += root->val;
        calculateSum(root->left, totalSum);
        calculateSum(root->right, totalSum);
    }

    ll preOrder(TreeNode *root, ll &totalSum, ll &ans){
        if(root == nullptr)
            return 0;
        
        ll leftSum = preOrder(root->left, totalSum, ans);
        ll rightSum = preOrder(root->right, totalSum, ans);

        ans = max({ans, leftSum * (totalSum - leftSum), rightSum * (totalSum - rightSum)});
        return leftSum + rightSum + root->val;
    }

    int maxProduct(TreeNode* root) {
        ll totalSum = 0;        
        ll ans = 0;
        calculateSum(root, totalSum);
        preOrder(root, totalSum, ans);
        return ans % MOD;
    }
};