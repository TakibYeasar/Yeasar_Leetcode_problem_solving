
// Problem link ===>> https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=problem-list-v2&envId=21ryaww3

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

TreeNode *build(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int> &mp)
{
    if (inStart > inEnd || postStart > postEnd)
        return nullptr;

    int rootVal = postorder[postEnd];
    TreeNode *root = new TreeNode(rootVal);
    int inRoot = mp[rootVal];
    int numsLeft = inRoot - inStart;

    root->left = build(inorder, postorder, inStart, inRoot - 1, postStart, postStart + numsLeft - 1, mp);
    root->right = build(inorder, postorder, inRoot + 1, inEnd, postStart + numsLeft, postEnd - 1, mp);

    return root;
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, mp);
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