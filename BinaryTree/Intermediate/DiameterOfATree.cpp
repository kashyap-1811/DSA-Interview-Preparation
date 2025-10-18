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

int Height(Node *root){
    if(root == nullptr)
        return 0;
    
    int h1 = Height(root->left) + 1;
    int h2 = Height(root->right) + 1;

    return max(h1,h2);
}

int Find_diameter_of_a_tree(Node *root){
    if(root == nullptr)
        return 0;

    int currDiameter = Height(root->left) + Height(root->right) + 1;
    int leftDiameter = Find_diameter_of_a_tree(root->left);
    int rightDiameter = Find_diameter_of_a_tree(root->right);

    return max(currDiameter,max(currDiameter,rightDiameter));
}

int main()
{
    vector<int>nodes = {1,2,3,4,-1,-1,5,-1,6,-1,-1,7,-1,8,-1,-1,9,10,-1,-1,11,-1,12,13,-1,-1,14,-1,15,-1,-1};

    Node *tree = buildTree(nodes);
    preOrderPrint(tree);

    int diameter = Find_diameter_of_a_tree(tree);
    cout<<endl<<"Diameter of the Tree = "<<diameter;
    return 0;
}