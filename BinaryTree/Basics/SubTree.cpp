#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    explicit Node(int data)
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

bool isIdentical(Node *root1, Node *root2){
    if(root1==nullptr && root2==nullptr)
        return true;
    else if(root1==nullptr || root2==nullptr)
        return false;

    if(root1->data != root2->data)
        return false;

    return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
}

bool is_SubTree(Node *root, Node *subroot)
{
    if(root==nullptr && subroot==nullptr)  
        return true;
    else if(root==nullptr || subroot==nullptr)
        return false;

    if(root->data == subroot->data){
        if(isIdentical(root,subroot))
            return true;
    }

    bool isExist = is_SubTree(root->left,subroot);
    if(!isExist)
        is_SubTree(root->right,subroot);

    return true;
}

int main()
{
    vector<int>nodes = {1,2,3,4,-1,-1,5,-1,6,-1,-1,7,-1,8,-1,-1,9,10,-1,-1,11,-1,12,13,-1,-1,14,-1,15,-1,-1};
    Node *root = buildTree(nodes);
    idx = -1;

    vector<int>nodes2 = {2,3,4,-1,-1,5,-1,6,-1,-1,7,-1,8,-1,-1};
    Node *subroot = buildTree(nodes2);

    bool isExist = is_SubTree(root,subroot);
    cout<<isExist;
    return 0;
}