// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// ==========> Solution
// Intuition
// The inorder traversal of a binary tree visits the left subtree, the root, and then the right subtree. 
// The goal is to accumulate the node values in the correct order.

// Approach
// We use a recursive helper function to perform the inorder traversal.
// In the helper function, we traverse the left subtree, add the root value to the result, and then traverse the right subtree.
// The base case ensures that the traversal stops when we reach a null node.
// Complexity
// Time Complexity: O(n), where n is the number of nodes in the binary tree. We visit each node once.
// Space Complexity: O(h), where h is the height of the binary tree. The space is used for the recursive call stack, 
// and in the worst case (skewed tree), it's O(n). In the average case (balanced tree), it's O(log n).

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

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode *root, vector<int> &result)
    {
        if (root != nullptr)
        {
            helper(root->left, result);
            result.push_back(root->val);
            helper(root->right, result);
        }
    }
};

int main()
{
    // Create a sample tree for demonstration
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Create an instance of the Solution class
    Solution solution;

    // Call the inorderTraversal function to get the inorder traversal sequence
    vector<int> result = solution.inorderTraversal(root);

    // Print the inorder traversal sequence
    cout << "Inorder traversal: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    // Clean up the tree memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}