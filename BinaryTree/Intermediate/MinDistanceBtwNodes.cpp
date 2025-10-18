#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }

    ~Node(){
        if(left != nullptr)
            delete left;
        if(right != nullptr)
            delete right;
    }
};

static int idx = -1;

Node* buildTree(vector<int>nodes)
{
    idx++;
    if(nodes[idx] == -1)
        return nullptr;

    Node *new_node = new Node(nodes[idx]);
    new_node->left = buildTree(nodes);
    new_node->right = buildTree(nodes);

    return new_node;
}

Node *findLCA(Node *root,int n1,int n2)
{
    if(root == nullptr)
        return nullptr;

    if(root->data=n1 || root->data==n2)
        return root;
    
    Node *left = findLCA(root->left,n1,n2);
    Node *right = findLCA(root->right,n1,n2);

    if(left!=nullptr && right!=nullptr)
        return root;
    
    return left==nullptr ? right : left;
}

int dist(Node *root,int n)
{
    if(root == nullptr)
        return -1;
    if(root->data == n)
        return 0;
    
    int leftDist = dist(root->left,n);
    if(leftDist != -1)
        return leftDist+1;
    
    int rightDist = dist(root->right,n);
    if(rightDist != -1)
        return rightDist+1;
    
    return -1;
}

int minDist(Node *root,int n1,int n2)
{
    Node *lca = findLCA(root,n1,n2);

    int dist1 = dist(lca,n1);
    int dist2 = dist(lca,n2);

    return dist1+dist2;
}

int main()
{
    vector<int>nodes = {1,2,3,4,-1,-1,5,-1,6,-1,-1,7,-1,8,-1,-1,9,10,-1,-1,11,-1,12,13,-1,-1,14,-1,15,-1,-1};
    Node *root = buildTree(nodes);
    
    int n1 = 4;
    int n2 = 15;

    cout<<minDist(root,n1,n2);
    return 0;
}