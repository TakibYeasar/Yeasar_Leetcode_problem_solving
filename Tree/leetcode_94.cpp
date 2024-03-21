// Problem Link ====>>https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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