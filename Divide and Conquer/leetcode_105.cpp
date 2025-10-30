
// Problem link ===>> https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=problem-list-v2&envId=21ryaww3

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define endl '\n'
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V>
using ordered_map = tree<
    K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;


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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
        {
            return nullptr;
        }

        int root_val = preorder[0];
        TreeNode *root = new TreeNode(root_val);

        auto it = find(inorder.begin(), inorder.end(), root_val);
        int inorder_index = distance(inorder.begin(), it);

        vector<int> left_inorder(inorder.begin(), inorder.begin() + inorder_index);
        vector<int> right_inorder(inorder.begin() + inorder_index + 1, inorder.end());

        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
        vector<int> right_preorder(preorder.begin() + 1 + left_inorder.size(), preorder.end());

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        
    }
    return 0;
}