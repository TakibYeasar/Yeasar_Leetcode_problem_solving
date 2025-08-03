
// Problem link ===>> https://leetcode.com/problems/mirror-reflection/description/?envType=problem-list-v2&envId=21r1b7y6

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
using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution
{
private:
    long long gcd(long long a, long long b)
    {
        while (b)
        {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return abs(a);
    }

    long long lcm(long long a, long long b)
    {
        return a * b / gcd(a, b);
    }

public:
    int mirrorReflection(int p, int q)
    {
        long long reflectionTime = lcm(p, q);

        bool isRightSide = (reflectionTime / q) % 2 == 1;
        bool isTopSide = (reflectionTime / p) % 2 == 1;

        if (isRightSide && isTopSide)
            return 1;
        else if (!isRightSide && isTopSide)
            return 2;

        return 0;
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