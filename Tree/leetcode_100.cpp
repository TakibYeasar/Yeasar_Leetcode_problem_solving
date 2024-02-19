// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
// Input: p = [1,2,1], q = [1,1,2]
// Output: false

// Constraints:
// The number of nodes in both trees is in the range [0, 100].
// -104 <= Node.val <= 104.

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            // Both trees are empty
            return true;
        }
        else if (!p || !q)
        {
            // One tree is empty, the other is not
            return false;
        }
        else
        {
            // Compare node values and recursively check left and right subtrees
            return (p->val == q->val) &&
                   isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        }
    }
};

int main()
{
    // Example usage
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);

    Solution sol;
    cout << (sol.isSameTree(p, q) ? "true" : "false") << endl;

    return 0;
}
