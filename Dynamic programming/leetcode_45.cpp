
// Problem link ===>>  https://leetcode.com/problems/jump-game-ii/description/
// submission link ===>> https://leetcode.com/problems/jump-game-ii/submissions/1489867235/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int near = 0, far = 0, jumps = 0;

        while(far<nums.size() - 1){
            int farthest = 0;
            for (int i = near; i <= far; i++){
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }
        return jumps;
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