// Problem Link ====>>https://leetcode.com/problems/plus-one/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry == 1)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main()
{
    Solution s;
    vector<int> digits = {1, 2, 3};
    vector<int> result = s.plusOne(digits);

    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ", ";
    }
    cout << "]" << endl; // prints [2, 3, 4]

    return 0;
}