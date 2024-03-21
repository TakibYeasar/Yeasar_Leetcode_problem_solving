// Problem Link ====>>https://leetcode.com/problems/validate-binary-search-tree/description/

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