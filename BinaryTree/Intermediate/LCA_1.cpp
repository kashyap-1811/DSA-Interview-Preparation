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

bool findPath(Node *root,int k,vector<int>&path)
{
    if(root == nullptr)
        return false;

    path.push_back(root->data);

    if(root->data == k)
        return true;
    
    bool check = findPath(root->left,k,path);
    if(!check)
    {
        check = findPath(root->right,k,path);
    }
    if(check == false)
    {
        path.pop_back();
        return false;
    }

    return true;
}

int findLCA(vector<int>p1, vector<int>p2)
{
    int lca = -1;

    for(int i=0; i<p1.size()&&i<p2.size();i++)
    {
        if(p1[i] != p2[i])
            return lca;
        lca = p1[i];
    }
    return lca;
}

int main()
{
    vector<int>nodes = {1,2,3,4,-1,-1,5,-1,6,-1,-1,7,-1,8,-1,-1,9,10,-1,-1,11,-1,12,13,-1,-1,14,-1,15,-1,-1};
    Node *root = buildTree(nodes);
    cout<<"Give the node values: ";
    int n1,n2;
    cin>>n1>>n2;

    vector<int>path1;
    bool check1 = findPath(root,n1,path1);
    vector<int>path2;
    bool check2 = findPath(root,n2,path2);

    for(auto it : path1)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it: path2)
    {
        cout<<it<<" ";
    }
    cout<<endl;

    if(!check1 || !check2){
        cout<<"Path do not found";
        return 0;
    }

    cout<<findLCA(path1,path2);
    return 0;
}