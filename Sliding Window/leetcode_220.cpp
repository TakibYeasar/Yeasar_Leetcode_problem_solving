
// Problem link ===>> https://leetcode.com/problems/contains-duplicate-iii/description/?envType=problem-list-v2&envId=21r1z5od

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
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int n = nums.size();
        if(n==0 || k<0 || t<0){
            return false;
        }

        unordered_map<int, int> buckets;
        for (int i = 0; i < n; i++){
            int bucket = nums[i] / ((long)t + 1);

            if(nums[i]<0)
                --bucket;
            
            if(buckets.find(bucket) != buckets.end()){
                return true;
            } else {
                buckets[bucket] = nums[i];

                if(buckets.find(bucket - 1) != buckets.end() && abs((long)nums[i] - buckets[bucket - 1]) <= t){
                    return true;
                }
                if(buckets.find(bucket + 1) != buckets.end() && abs((long)nums[i] - buckets[bucket + 1]) <= t){
                    return true;
                }

                if (buckets.size() > k)
                {
                    int key_to_remove = nums[i - k] / ((long)t + 1);

                    if (nums[i - k] < 0)
                        --key_to_remove;

                    buckets.erase(key_to_remove);
                }
            }
        }
        return false;
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