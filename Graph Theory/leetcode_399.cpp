
// Problem link ===>> https://leetcode.com/problems/evaluate-division/description/?envType=problem-list-v2&envId=21rco0xh

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
    void dfs(string node, string &dest, unordered_map<string, unordered_map<string, double>> &gr, unordered_set<string> &vis, double &ans, double temp)
    {
        if (vis.find(node) != vis.end())
            return;

        vis.insert(node);
        if (node == dest)
        {
            ans = temp;
            return;
        }

        for (auto ne : gr[node])
        {
            dfs(ne.first, dest, gr, vis, ans, temp * ne.second);
        }
    }

    unordered_map<string, unordered_map<string, double>> buildGraph(const vector<vector<string>> &equations, const vector<double> &values)
    {
        unordered_map<string, unordered_map<string, double>> gr;

        for (int i = 0; i < equations.size(); i++)
        {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double value = values[i];

            gr[dividend][divisor] = value;
            gr[divisor][dividend] = 1.0 / value;
        }

        return gr;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> gr = buildGraph(equations, values);
        vector<double> finalAns;

        for (auto query : queries)
        {
            string dividend = query[0];
            string divisor = query[1];

            if (gr.find(dividend) == gr.end() || gr.find(divisor) == gr.end())
            {
                finalAns.push_back(-1.0);
            }
            else
            {
                unordered_set<string> vis;
                double ans = -1, temp = 1.0;
                dfs(dividend, divisor, gr, vis, ans, temp);
                finalAns.push_back(ans);
            }
        }

        return finalAns;
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