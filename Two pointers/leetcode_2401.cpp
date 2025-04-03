
// Problem link ===>> https://leetcode.com/problems/longest-nice-subarray/description/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// class Solution
// {
// public:
//     int longestNiceSubarray(vector<int> &nums)
//     {
//         int l = 0, r = 0;
//         int n = nums.size();
//         vector<int> cnt(30, 0);
//         int mx = 0;

//         while (r < n)
//         {
//             int x = nums[r];
//             bool is_valid = true;

//             for (int i = 0; i < 30; i++)
//             {
//                 if (x & (1 << i))
//                 {
//                     cnt[i]++;
//                     if (cnt[i] >= 2)
//                     {
//                         is_valid = false;
//                     }
//                 }
//             }

//             while (!is_valid)
//             {
//                 int y = nums[l];
//                 l++;

//                 for (int i = 0; i < 30; i++)
//                 {
//                     if (y & (1 << i))
//                     {
//                         cnt[i]--;
//                     }
//                 }

//                 is_valid = true;
//                 for (int i = 0; i < 30; i++)
//                 {
//                     if (cnt[i] >= 2)
//                     {
//                         is_valid = false;
//                         break;
//                     }
//                 }
//             }

//             mx = max(mx, r - l + 1);
//             r++;
//         }

//         return mx;
//     }
// };

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int mx = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int check = 0;
            for (int j = i; j < n; j++)
            {
                if(check & nums[j]){
                    break;
                } else {
                    mx = max(mx, j - i + 1);
                    check |= nums[j];
                }
            }
        }
        return mx;
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