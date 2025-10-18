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

pair<int,int> Diameter(Node *root)
{
    if(root == nullptr)
        return make_pair(0,0);
    
    pair<int,int> leftInfo = Diameter(root->left); // Left diameter, left height
    pair<int,int> rightInfo = Diameter(root->right); // right diameter, right height

    int currDiameter = leftInfo.second + rightInfo.second + 1; //current node diameter
    int currHeight = max(leftInfo.second,rightInfo.second) + 1;
    currDiameter = max(currDiameter, max(leftInfo.first,rightInfo.first));

    return make_pair(currDiameter,currHeight);

}

int main()
{
    vector<int>nodes = {1,2,3,4,-1,-1,5,-1,6,-1,-1,7,-1,8,-1,-1,9,10,-1,-1,11,-1,12,13,-1,-1,14,-1,15,-1,-1};

    Node *tree = buildTree(nodes); // root = tree
    preOrderPrint(tree);

    pair<int,int> diameter_height = Diameter(tree);
    cout<<endl<<"Diameter of the tree is = "<<diameter_height.first;
    cout<<endl<<"Height of the tree is = "<<diameter_height.second;
    return 0;
}