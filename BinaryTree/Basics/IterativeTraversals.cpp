// https://leetcode.com/problems/binary-tree-preorder-traversal/
// https://leetcode.com/problems/binary-tree-inorder-traversal/
// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *curr = root;

    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        ans.push_back(curr->val);
        curr = curr->right;
    }

    return ans;
}

vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    s.push(root);
    vector<int> ans;

    while (!s.empty())
    {
        TreeNode *curr = s.top();
        s.pop();

        if (curr == nullptr)
            continue;

        ans.push_back(curr->val);
        s.push(curr->right);
        s.push(curr->left);
    }

    return ans;
}

vector<int> postorderTraversalUsingTwoStack(TreeNode *root)
{
    vector<int> result;

    // If the root is null, return an empty list
    if (!root)
    {
        return result;
    }

    // Stack to manage the traversal
    stack<TreeNode *> mainStack;
    // Stack to manage the path
    stack<TreeNode *> pathStack;

    // Start with the root node
    mainStack.push(root);

    // Process nodes until the main stack is empty
    while (!mainStack.empty())
    {
        root = mainStack.top();

        // If the node is in the path stack and it's the top, add its value
        if (!pathStack.empty() && pathStack.top() == root)
        {
            result.push_back(root->val);
            mainStack.pop();
            pathStack.pop();
        }
        else
        {
            // Push the current node to the path stack
            pathStack.push(root);
            // Push right child if it exists
            if (root->right)
            {
                mainStack.push(root->right);
            }
            // Push left child if it exists
            if (root->left)
            {
                mainStack.push(root->left);
            }
        }
    }

    return result;
}

vector<int> postorderTraversalUsingOneStack(TreeNode *root)
{
    vector<int> result;

    // If the root is null, return an empty list
    if (root == nullptr)
    {
        return result;
    }

    // To keep track of the previously processed node
    TreeNode *previousNode = nullptr;
    // Stack to manage the traversal
    stack<TreeNode *> traversalStack;

    // Process nodes until both the root is null and the stack is empty
    while (root != nullptr || !traversalStack.empty())
    {
        // Traverse to the leftmost node
        if (root != nullptr)
        {
            traversalStack.push(root);
            root = root->left;
        }
        else
        {
            // Peek at the top node of the stack
            root = traversalStack.top();

            // If there is no right child or the right child was already processed
            if (root->right == nullptr || root->right == previousNode)
            {
                result.push_back(root->val);
                traversalStack.pop();
                previousNode = root;
                root = nullptr; // Ensure we don’t traverse again from this node
            }
            else
            {
                // Move to the right child
                root = root->right;
            }
        }
    }

    return result;
}