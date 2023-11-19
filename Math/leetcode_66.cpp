// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
// The digits are ordered from most significant to least significant in left - to - right order.The large integer does
// not contain any leading 0's. return the resulting array of digits.

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