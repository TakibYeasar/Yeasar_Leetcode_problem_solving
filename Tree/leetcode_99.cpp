// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
// Recover the tree without changing its structure.

// Input: root = [3,1,4,null,null,2]
// Output: [2,1,4,null,null,3]
// Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

// Constraints:
// The number of nodes in the tree is in the range [2, 1000].
// -231 <= Node.val <= 231 - 1
 
// Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?

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
