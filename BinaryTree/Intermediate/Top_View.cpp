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

void topView(Node *root)
{
    queue<pair<Node*,int>>q; //Node pointer and horizontal distance
    map<int,int>m; //HORIZONTAL DISTANCE, node value

    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<Node*,int>curr = q.front(); q.pop();

        Node *currNode = curr.first;
        int currHD = curr.second;

        if(!m.count(currHD))
        {
            m[currHD] = currNode->data;
        }

        if(currNode->left != nullptr)
        {
            pair<Node*,int>left = make_pair(currNode->left, currHD-1);
            q.push(left);
        }

        if(currNode->right != nullptr)
        {
            pair<Node*,int>right = make_pair(currNode->right, currHD+1);
            q.push(right);
        }
    }

    for(auto it : m)
    {
        cout<<it.second<<" ";
    }
}

int main()
{
    vector<int>nodes = {1,2,3,4,-1,-1,5,-1,6,-1,-1,7,-1,8,-1,-1,9,10,-1,-1,11,-1,12,13,-1,-1,14,-1,15,-1,-1};
    Node *root = buildTree(nodes);

    topView(root);
    return 0;
}