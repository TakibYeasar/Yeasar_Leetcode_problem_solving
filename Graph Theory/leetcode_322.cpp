
// Problem link ===>> https://leetcode.com/problems/reconstruct-itinerary/description/?envType=problem-list-v2&envId=21rco0xh

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
private:
    unordered_map<string, multiset<string, greater<string>>> flightGraph;
    vector<string> itinerary;

public:
    void dfs(string airport)
    {
        auto &destinations = flightGraph[airport];

        while (!destinations.empty())
        {
            auto nextDestination = *(--destinations.end());
            destinations.erase(--destinations.end());
            dfs(nextDestination);
        }
        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (int i = 0; i < tickets.size(); i++)
        {
            string from = tickets[i][0];
            string to = tickets[i][1];
            flightGraph[from].insert(to);
        }

        dfs("JFK");

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
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