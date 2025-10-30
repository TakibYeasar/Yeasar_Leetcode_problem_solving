
// Problem link ===>> https://leetcode.com/problems/number-of-provinces/description/?envType=problem-list-v2&envId=21rco0xh

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

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        function<void(int)> dfs = [&](int city)
        {
            visited[city] = true;
            for (int neighbor = 0; neighbor < n; neighbor++)
            {
                if (isConnected[city][neighbor] == 1 && !visited[neighbor])
                {
                    dfs(neighbor);
                }
            }
        };

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                provinces++;
                dfs(i);
            }
        }

        return provinces;
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