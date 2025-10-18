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

int main()
{
    vector<int>nodes = {1,2,3,4,-1,-1,5,-1,6,-1,-1,7,-1,8,-1,-1,9,10,-1,-1,11,-1,12,13,-1,-1,14,-1,15,-1,-1};
    Node *root = buildTree(nodes);
    cout<<"Enter the level nodes to be printed: ";
    int k; cin>>k;

    queue<Node*>q;
    q.push(root);
    q.push(nullptr);
    int count = 1;

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if(count == k)
        {
            while(curr != nullptr)
            {
                cout<<curr->data<<" ";
                curr = q.front();
                q.pop();
            }
            break;
        }

        if(curr == nullptr)
        {
            if(q.empty())
                break;
            q.push(nullptr);
            count++;
        }
        else{
            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);
        }
    }
    return 0;
}