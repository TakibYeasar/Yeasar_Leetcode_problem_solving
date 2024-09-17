
// Problem link ===>>  https://leetcode.com/problems/multiply-strings/description/
// submission link ===>> https://leetcode.com/problems/multiply-strings/submissions/1386665500/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1=="0" || num2=="0"){
            return "0";
        }

        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> result(len1 + len2, 0);

        for (int i = len1 - 1; i >= 0; --i)
        {
            for (int j = len2 - 1; j >= 0; --j)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0'); // Product of current digits
                int p1 = i + j;                              // Carry position
                int p2 = i + j + 1;                          // Remainder position

                int sum_carry = mul + result[p2];

                result[p2] = sum_carry % 10;  // Store remainder
                result[p1] += sum_carry / 10; // Add carry to the next position
            }
        }

        // Convert result vector to string, removing leading zeros
        string result_str = "";
        bool leading_zero = true;

        for (int num : result)
        {
            if (leading_zero && num == 0)
            {
                continue; // Skip leading zeros
            }
            leading_zero = false;
            result_str += to_string(num); // Append non-zero digits
        }

        return result_str.empty() ? "0" : result_str;
    }
};

int main()
{
    // Optimizing input/output speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t;
    cin >> t;
    while (t--)
    {
        string num1, num2;
        cin >> num1 >> num2;

        Solution s;
        string result = s.multiply(num1, num2);
        cout << result<<endl;
    }
    return 0;
}