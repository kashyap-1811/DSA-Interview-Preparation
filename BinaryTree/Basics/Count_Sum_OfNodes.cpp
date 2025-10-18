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

void preOrderPrint(Node *root){
    if(root == nullptr)
        return;
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int total_nodes(Node *root)
{
    if(root == nullptr)
        return 0;

    int left_nodes = total_nodes(root->left);

    int right_nodes = total_nodes(root->right);

    return left_nodes+right_nodes+1;
}

int total_sum(Node *root)
{
    if(root == nullptr)
        return 0;
    
    int left_sum = total_sum(root->left);
    int right_sum = total_sum(root->right);

    return left_sum + right_sum + root->data;

}

int main()
{
    vector<int>nodes = {1,2,3,4,-1,-1,5,-1,6,-1,-1,7,-1,8,-1,-1,9,10,-1,-1,11,-1,12,13,-1,-1,14,-1,15,-1,-1};

    Node *root = buildTree(nodes);
    preOrderPrint(root);

    int count = total_nodes(root);
    cout<<endl<<"Total Nodes in the trees are = "<<count<<endl;

    int sum = total_sum(root);
    cout<<"Sum of all nodes is = "<<sum;

    return 0;
}