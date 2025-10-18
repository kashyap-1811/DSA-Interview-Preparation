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

    ~Node()
    {
        if(left != nullptr)
            delete left;
        if(right != nullptr)
            delete right;
    }
};

Node* insert_iterative(Node *root, int value)
{
    Node *new_node = new Node(value);
    if(root == nullptr)
        return new_node;
    
    Node *temp = root;
    Node *parent = nullptr;

    while(temp != nullptr)
    {
        parent = temp;
        if(temp->data > value)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(parent!=nullptr && parent->data > value)
        parent->left = new_node;
    else if(parent!=nullptr && parent->data < value)
        parent->right = new_node;

    return root;
}

bool checkBST(Node *root, Node *min, Node *max)
{
    if(root == nullptr)
        return true;

    if(min!=nullptr && root->data<min->data)
        return false;
    if(max!=nullptr && root->data>max->data)
        return false;

    return checkBST(root->left,min,root) && checkBST(root->right,root,max);
}

bool ValidateBST(Node *root)
{
    return checkBST(root,nullptr,nullptr);
}

int main()
{
    vector<int>arr2 = {5,3,8,2,4,7,10,1,6,9,12,11,13};

    Node *root = nullptr;
    for(auto i : arr2){
        root = insert_iterative(root,i);
    }

    //root->data  = 2;
    cout<<ValidateBST(root);
    return 0;
}