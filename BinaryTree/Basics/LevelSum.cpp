#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
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

static int idx=-1;
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

void preOrderprintTree(Node *root)
{
    if(root == nullptr)
        return;

    cout<<root->data<<" ";         //root
    preOrderprintTree(root->left); //left
    preOrderprintTree(root->right);//right
}

int main()
{
    vector<int>nodes ={
        1,2,4,-1,-1,5,-1,-1,3,-1,6,7,-1,-1,-1
    };

    Node *root = buildTree(nodes);
    cout<<"print using preOrdera: ";
    preOrderprintTree(root);
    cout<<endl;

    if(root == nullptr)
    {
        cout<<"NULL";
        return 0;
    }
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    int count = 0;
    while(!q.empty())
    {
        Node *curr = q.front();q.pop();
        if(curr == nullptr)
        {
            cout<<count<<endl;
            count = 0;
            if(q.empty())
                break;
            q.push(nullptr);
        }
        else
        {
            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);
            count += curr->data;
        }
    }
    return 0;
}