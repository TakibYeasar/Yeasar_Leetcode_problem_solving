
// Problem link ===>> https://leetcode.com/problems/powx-n/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {

        if (n < 0)
        {
            x = 1 / x;
        }

        long num = labs(n);

        double pow = 1;

        while (num)
        { // equivalent to while(num != 0)
            if (num & 1)
            { // equivalent to if((num & 1) != 0)
                pow *= x;
            }

            x *= x;
            num >>= 1;
        }

        return pow;
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