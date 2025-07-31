
// Problem link ===>> https://leetcode.com/problems/minimum-height-trees/description/?envType=problem-list-v2&envId=21rco0xh

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
template <typename T>
using ordered_set_mul = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n < 3)
        {
            vector<int> result(n);
            iota(result.begin(), result.end(), 0);
            return result;
        }

        vector<set<int>> adjacency_list(n);
        for (const auto &edge : edges)
        {
            adjacency_list[edge[0]].insert(edge[1]);
            adjacency_list[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;
        for (int i = 0; i < n; ++i)
        {
            if (adjacency_list[i].size() == 1)
            {
                leaves.push_back(i);
            }
        }

        int remaining_nodes = n;
        while (remaining_nodes > 2)
        {
            remaining_nodes -= leaves.size();
            vector<int> new_leaves;
            for (int leaf : leaves)
            {
                int neighbor = *adjacency_list[leaf].begin();
                adjacency_list[neighbor].erase(leaf);
                if (adjacency_list[neighbor].size() == 1)
                {
                    new_leaves.push_back(neighbor);
                }
            }
            leaves = new_leaves;
        }

        return leaves;
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