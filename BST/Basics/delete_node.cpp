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


/*--------------------------------------------------------------------------------------------------------*/
Node* insert(Node *root, int data)  //O(logn)
{
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(root->data > data)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    return root;
}

Node* create_BST(const vector<int>&arr, int n) //O(nlogn) in general
{
    Node *root = nullptr;

    for(int i=0;i<n;i++)//O(n)
    {
        root = insert(root,arr[i]);
    }

    return root;
}
/*--------------------------------------------------------------------------------------------------------*/

bool search(Node *root, int key) //O(height) //worst for skewed BST O(n)-> where just left or right branches are there
{
    if(root == nullptr)
        return false;
    else if(root->data == key)
        return true;
    else if(root->data > key)
        return search(root->left, key);
    else
        return search(root->right,key);
}

void inOrder(Node *root)
{
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node* inOrderSuccessor(Node *root)
{
    if(root->left == nullptr)
        return root;
    return inOrderSuccessor(root->left);
}

Node* to_delete_node(Node *root,int val)
{
    if(root == nullptr)
        return nullptr;

    else if(val < root->data)
        root->left = to_delete_node(root->left,val);

    else if(val > root->data)
        root->right = to_delete_node(root->right,val);

    else{ //val == root->data
        
        if(root->left==nullptr && root->right==nullptr)       //case 1: 0 child
        {
            delete root;
            return nullptr;
        }
        else if(root->left==nullptr || root->right==nullptr)  //case 2:  1 child
        {
            Node *temp;
            if(root->left != nullptr){
                temp = root->left;
                root->left = nullptr;
            }
            else{
                temp = root->right;
                root->right = nullptr;
            }

            delete root;
            return temp;
        }

        else{                                                  //case 3: 2 childs
            Node *iS = inOrderSuccessor(root->right);
            root->data = iS->data;
            to_delete_node(iS, iS->data);
        }

        return root;
    }
}

Node* delete_node(Node *root,int val){
    if(root == nullptr)
        return nullptr;
    
    if(root->data < val)
        root->right = delete_node(root->right,val);
    else if(root->data > val)
        root->left = delete_node(root->left,val);
    else{
        //case 0:
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        //case 1:
        else if(root->left==nullptr || root->right==nullptr)
        {
            Node *temp;
            if(root->left==nullptr)
            {
                temp = root->right;
                root->right = nullptr;
            }
            else{
                temp = root->left;
                root->left = nullptr;
            }

            delete root;
            return temp;
        }

        //case 2:
        else{
            Node *iS = inOrderSuccessor(root->right);
            root->data = iS->data;

            root->right = delete_node(root->right,iS->data);
        }

        return root;
    }
}

int main()
{
    vector<int>arr2 = {2,3,1,9,8,7,10,4,5,6,11};
    
    Node *root = create_BST(arr2,arr2.size());

    inOrder(root);
    cout<<endl;

    delete_node(root,6);  //0 child
    delete_node(root,4);  //1 child
    delete_node(root,9); //2 child

    inOrder(root);

    return 0;
}