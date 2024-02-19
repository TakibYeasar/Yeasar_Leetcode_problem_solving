// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of 
// unique values from 1 to n. Return the answer in any order.

#include<bits/stdc++.h>
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

// Approach Recursion

// class Solution
// {
// public:
//     vector<TreeNode *> generateTrees(int n)
//     {
//         return n ? generate_trees(1, n) : vector<TreeNode *>();
//     }

// private:
//     vector<TreeNode *> generate_trees(int start, int end)
//     {
//         if (start > end)
//             return {nullptr};

//         vector<TreeNode *> all_trees;
//         for (int i = start; i <= end; i++)
//         {
//             vector<TreeNode *> left_trees = generate_trees(start, i - 1);
//             vector<TreeNode *> right_trees = generate_trees(i + 1, end);

//             for (TreeNode *l : left_trees)
//             {
//                 for (TreeNode *r : right_trees)
//                 {
//                     TreeNode *current_tree = new TreeNode(i);
//                     current_tree->left = l;
//                     current_tree->right = r;
//                     all_trees.push_back(current_tree);
//                 }
//             }
//         }
//         return all_trees;
//     }
// };

// Dynamic Programming

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};

        vector<vector<TreeNode *>> dp(n + 1);
        dp[0].push_back(nullptr);
        for (int nodes = 1; nodes <= n; nodes++)
        {
            for (int root = 1; root <= nodes; root++)
            {
                for (TreeNode *left_tree : dp[root - 1])
                {
                    for (TreeNode *right_tree : dp[nodes - root])
                    {
                        TreeNode *root_node = new TreeNode(root);
                        root_node->left = left_tree;
                        root_node->right = clone(right_tree, root);
                        dp[nodes].push_back(root_node);
                    }
                }
            }
        }
        return dp[n];
    }

private:
    TreeNode *clone(TreeNode *n, int offset)
    {
        if (n == nullptr)
            return nullptr;
        TreeNode *node = new TreeNode(n->val + offset);
        node->left = clone(n->left, offset);
        node->right = clone(n->right, offset);
        return node;
    }
};

int main(){
    
    return 0;
}