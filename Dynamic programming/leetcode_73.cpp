
// Problem link ===>> https://leetcode.com/problems/set-matrix-zeroes/?envType=problem-list-v2&envId=21r4yhih

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
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool zeroFirstCol = false;

        for (int row = 0; row < matrix.size(); row++){
            if(matrix[row][0] ==0)
                zeroFirstCol = true;
            for (int col = 1; col < matrix[0].size(); col++){
                if(matrix[row][col] == 0){
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = matrix.size() - 1; row >= 0; row--){
            for (int col = matrix[0].size() - 1; col >= 1; col--){
                if(matrix[row][0] == 0 || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
            if(zeroFirstCol){
                matrix[row][0] = 0;
            }
        }
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