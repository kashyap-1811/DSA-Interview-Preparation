#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    explicit Node(int data){
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

int Height(Node *root)
{
    if(root == nullptr)
        return 0;

    int h1 = 1;
    h1 += Height(root->left);

    int h2 = 1;
    h2 += Height(root->right);

    return max(h1,h2);
}

int main()
{
    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,7,8,9,-1,-1,-1,-1,-1};
    Node *root = buildTree(nodes);

    //printing tree level wise
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if(curr == nullptr)
        {
            cout<<endl;
            if(q.empty())
                break;
            q.push(nullptr);
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);
        }
    }

    int height = Height(root);
    cout<<"Height of the Tree = "<<height;
    return 0;
}