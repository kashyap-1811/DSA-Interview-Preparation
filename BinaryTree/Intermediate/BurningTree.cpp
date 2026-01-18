// https://www.geeksforgeeks.org/problems/burning-tree/1
 
#include <bits/stdc++.h>
using namespace std;
 
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void traverse(Node *root, unordered_map<Node*, Node*> &m, Node *parent, int &target, Node* &targetNode){
        if(!root) return;
        
        if(root->data == target)
            targetNode = root;
        m[root] = parent;
        traverse(root->left, m, root, target, targetNode);
        traverse(root->right, m, root, target, targetNode);
    }
    
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> m;
        unordered_set<Node*> s;
        Node *targetNode = nullptr;
        traverse(root, m, nullptr, target, targetNode);
        
        queue<Node*> q;
        q.push(targetNode);
        s.insert({targetNode});
        int steps = 0;
        
        while(!q.empty()){
            queue<Node*> newQueue;
            
            while(!q.empty()){
                Node *curr = q.front();
                q.pop();
                
                if(m[curr] && !s.count(m[curr])){
                    newQueue.push(m[curr]);
                    s.insert({m[curr]});
                }if(curr->left && !s.count(curr->left)){
                    newQueue.push(curr->left);
                    s.insert({curr->left});
                }if(curr->right && !s.count(curr->right)){
                    newQueue.push(curr->right);
                    s.insert({curr->right});
                }
            }
            
            if(newQueue.size())
                steps++;
            q.swap(newQueue);
        }
        
        return steps;
    }
};