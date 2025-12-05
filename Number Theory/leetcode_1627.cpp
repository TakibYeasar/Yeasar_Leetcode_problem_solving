
// Problem link ===>> https://leetcode.com/problems/graph-connectivity-with-threshold/description/?envType=problem-list-v2&envId=21r1b7y6

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

class UnionFind{
    public:
        vector<int> root, rankv;

        UnionFind(int n){
            root.resize(n);
            rankv.assign(n, 1);
            for (int i = 0; i < n; i++)
                root[i] = i;
        }

        int find(int x){
            if(root[x] != x)
                root[x] = find(root[x]);
            return root[x];
        }

        void unite(int x, int y)
        {
            int rx = find(x), ry = find(y);
            if (rx == ry)
                return;

            if (rankv[rx] > rankv[ry])
            {
                root[ry] = rx;
            }
            else if (rankv[rx] < rankv[ry])
            {
                root[rx] = ry;
            }
            else
            {
                root[ry] = rx;
                rankv[rx]++;
            }
        }

        bool isConnected(int x, int y)
        {
            return find(x) == find(y);
        }
};

class Solution
{
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries)
    {
        UnionFind uf(n + 1);

        for (int z = threshold + 1; z <= n; z++)
        {
            for (int x = z + z; x <= n; x += z)
            {
                uf.unite(z, x);
            }
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (auto &q : queries)
        {
            ans.push_back(uf.isConnected(q[0], q[1]));
        }

        return ans;
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