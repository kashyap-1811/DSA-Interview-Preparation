// #include <bits/stdc++.h>

// using namespace std;

// class Node{
//     public:
//     int data;
//     Node *left;
//     Node *right;

//     explicit Node(int data)
//     {
//         this->data = data;
//         left = right = nullptr;
//     }

//     ~Node()
//     {
//         if(left != nullptr)
//             delete left;
//         if(right != nullptr)
//             delete right;
//     }
// };

// Node* insert(Node *root, int data)  //O(logn)
// {
//     if(root == nullptr){
//         root = new Node(data);
//         return root;
//     }

//     if(root->data > data)
//         root->left = insert(root->left,data);
//     else
//         root->right = insert(root->right,data);
//     return root;
// }

// Node* insert_iterative(Node *root, int value)
// {
//     Node *new_node = new Node(value);
//     if(root == nullptr)
//         return new_node;
    
//     Node *temp = root;
//     Node *parent = nullptr;

//     while(temp != nullptr){
//         parent = temp;
//         if(temp->data < value)
//             temp = temp->right;
//         else
//             temp = temp->left;
//     }

//     if(parent->data < value)
//         parent->right = new_node;
//     else
//         parent->left = new_node;
//     return root;
// }

// Node* create_BST(const vector<int>&arr, int n) //O(nlogn) in general
// {
//     Node *root = nullptr;

//     for(int i=0;i<n;i++)//O(n)
//     {
//         root = insert_iterative(root,arr[i]);
//     }

//     return root;
// }

// bool search(Node *root, int key) //O(height) //worst for skewed BST O(n)-> where just left or right branches are there
// {
//     if(root == nullptr)
//         return false;
//     else if(root->data == key)
//         return true;
//     else if(root->data > key)
//         return search(root->left, key);
//     else
//         return search(root->right,key);
// }

// bool search_iterative(Node *root, int key){
//    Node *temp = root;
//    while(temp != nullptr)
//    {
//         if(temp->data == key)
//             return true;
//         else if(temp->data > key)
//             temp = temp->left;
//         else
//             temp = temp->right;
//    }
//    return false;
// }

// Node* delete_iterative(Node *root, int key) {
//     Node *curr = root;
//     Node *parent = nullptr;

//     while(curr != nullptr && curr->data != key) {
//         parent = curr;
//         if(curr->data > key)
//             curr = curr->left;
//         else
//             curr = curr->right;
//     }

//     if(curr == nullptr) {  // Key not found
//         cout << "-1" << endl;
//         return root;
//     }

//     // Case 1: Node to be deleted is a leaf node (no children)
//     if(curr->left == nullptr && curr->right == nullptr) {
//         if(curr == root) {
//             root = nullptr;
//         } else if(parent->left == curr) {
//             parent->left = nullptr;
//         } else {
//             parent->right = nullptr;
//         }
//         delete curr;
//     }
//     // Case 2: Node to be deleted has only one child
//     else if(curr->left == nullptr || curr->right == nullptr) {
//         Node* child;
//         if(curr->left != nullptr){
//             child = curr->left;
//             curr->left = nullptr;
//         }else{
//             child = curr->right;
//             curr->right = nullptr;
//         }

//         if(curr == root) {
//             root = child;
//         } else if(parent->left == curr) {
//             parent->left = child;
//         } else {
//             parent->right = child;
//         }
//         delete curr;
//         return root;
//     }
//     // Case 3: Node to be deleted has two children
//     else {
//         Node *iS = curr->right;
//         Node *iSParent = curr;

//         // Find the in-order successor (leftmost child of right subtree)
//         while(iS->left != nullptr) {
//             iSParent = iS;
//             iS = iS->left;
//         }

//         // Replace curr's data with the in-order successor's data
//         curr->data = iS->data;

//         // Remove the in-order successor node
//         if(iSParent->left == iS) {
//             iSParent->left = iS->right;
//         } else {
//             iSParent->right = iS->right;
//         }
//         delete iS;
//     }
//     return root;
// }

// void inOrder(Node *root)
// {
//     if(root == nullptr)
//         return;
//     inOrder(root->left);
//     cout<<root->data<<" ";
//     inOrder(root->right);
// }

// int main()
// {
//     vector<int>arr2 = {5,3,8,2,4,7,10,1,6,9,12,11,13};
    
//     Node *root = create_BST(arr2,arr2.size());

//     inOrder(root);
//     cout<<endl;

//     //  cout<<search_iterative(root,9)<<endl;
//     //  cout<<search_iterative(root,15)<<endl;
//      delete_iterative(root,4);
//      delete_iterative(root,2);
//      delete_iterative(root,8);
//      inOrder(root);

//     return 0;
// }