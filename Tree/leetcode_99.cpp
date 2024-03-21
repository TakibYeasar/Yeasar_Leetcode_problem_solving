// Problem Link ====>>https://leetcode.com/problems/recover-binary-search-tree/description/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *first = nullptr;  // First swapped node
        TreeNode *second = nullptr; // Second swapped node
        TreeNode *prev = nullptr;   // Previous node during in-order traversal

        // In-order traversal to find swapped nodes
        inorder(root, prev, first, second);

        // Swap the values of the two nodes
        swap(first->val, second->val);
    }

private:
    void inorder(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second)
    {
        if (!root)
            return;

        // Traverse left subtree
        inorder(root->left, prev, first, second);

        // Check for swapped nodes
        if (prev && root->val < prev->val)
        {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;

        // Traverse right subtree
        inorder(root->right, prev, first, second);
    }
};

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution sol;
    sol.recoverTree(root);

    // Print the corrected BST (in-order traversal)
    // You can implement the printInorder function similar to the previous examples
    // For simplicity, I'm not printing the result here

    return 0;
}
