
// Problem link ===>> https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/?envType=problem-list-v2&envId=21r1mgbr

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
    vector<vector<int>> rects;
    vector<long long> pref; // prefix area sum
    long long total = 0;

    Solution(vector<vector<int>> &rects)
    {
        this->rects = rects;
        pref.resize(rects.size());

        long long sum = 0;
        for (int i = 0; i < rects.size(); i++)
        {
            long long x1 = rects[i][0];
            long long y1 = rects[i][1];
            long long x2 = rects[i][2];
            long long y2 = rects[i][3];

            long long area = (x2 - x1 + 1) * 1LL * (y2 - y1 + 1);
            sum += area;
            pref[i] = sum;
        }
        total = sum;
    }

    vector<int> pick()
    {
        // random pick from [1, total]
        long long r = 1 + rand() % total;

        // binary search to find the rectangle index
        int idx = lower_bound(pref.begin(), pref.end(), r) - pref.begin();

        int x1 = rects[idx][0];
        int y1 = rects[idx][1];
        int x2 = rects[idx][2];
        int y2 = rects[idx][3];

        // pick a random point inside this rectangle
        int x = x1 + rand() % (x2 - x1 + 1);
        int y = y1 + rand() % (y2 - y1 + 1);

        return {x, y};
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