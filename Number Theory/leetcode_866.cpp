
// Problem link ===>> https://leetcode.com/problems/prime-palindrome/description/?envType=problem-list-v2&envId=21r1b7y6

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
    int primePalindrome(int n)
    {
        if(8 <= n && n<= 11) return 11;
        for (ll x = 1; x < 100000; ++x){
            string s = to_string(x);
            string r(s.rbegin(), s.rend());
            ll y = stoi(s + r.substr(1));
            if (y >= n && isPrime(y)) {
                return y;
            }
        }
        return -1;
    }
    bool isPrime(ll n)
    {
        if (n <2 || n%2 ==0){
            return n == 2;
        }
        for (ll i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
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