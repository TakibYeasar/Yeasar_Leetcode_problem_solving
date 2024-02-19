// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left 
// subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.
 

// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
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
    bool isValidBST(TreeNode *root)
    {
        return isPossible(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isPossible(TreeNode *root, long long left, long long right)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val <= left || root->val >= right)
        {
            return false;
        }

        return isPossible(root->left, left, root->val) && isPossible(root->right, root->val, right);
    }
};

int main(){

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    Solution solution;
    bool is_bst = solution.isValidBST(root);

    cout << "Is the tree a valid BST: " << (is_bst ? "Yes" : "No") << endl;

    delete root;

    return 0;
}