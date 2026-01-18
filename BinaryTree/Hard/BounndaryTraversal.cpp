// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
 
#include <bits/stdc++.h>
using namespace std;
 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void findLeft(Node *root, vector<int> &left){
        if(!root || (!root->left && !root->right))
            return;
        
        left.push_back(root->data);
        
        if(root->left)
            findLeft(root->left, left);
        else if(root->right)
            findLeft(root->right, left);
    }
    
    void findLeaves(Node *root, vector<int> &leaves){
        if(!root)
            return;
        if(!root->left && !root->right){
            leaves.push_back(root->data);
            return;
        }
        
        
        findLeaves(root->left, leaves);
        findLeaves(root->right, leaves);
    }
    
    void findRight(Node *root, vector<int> &right){
        if(!root || (!root->left && !root->right))
            return;
        
        right.push_back(root->data);
        
        if(root->right)
            findRight(root->right, right);
        else if(root->left)
            findRight(root->left, right);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> left, leaves, right;
        
        findLeft(root->left, left);
        if(root->left || root->right)
            findLeaves(root, leaves);
        findRight(root->right, right);
        
        vector<int> ans;
        ans.push_back(root->data);
        
        for(int &i : left)
            ans.push_back(i);
        for(int &i : leaves)
            ans.push_back(i);
        reverse(right.begin(), right.end());
        
        for(int &i : right)
            ans.push_back(i);
        
        return ans;
    }
};