// Problem Link ====>>https://leetcode.com/problems/add-binary/description/

#include<iostream>
    using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i] - '0';
            }
            if (j >= 0)
            {
                sum += b[j] - '0';
            }
            carry = sum / 2;
            result = char(sum % 2 + '0') + result;
            i--;
            j--;
        }
        if (carry == 1)
        {
            result = '1' + result;
        }
        return result;
    }
};

int main(){
    Solution s;
    string result = s.addBinary("11", "1");
    cout << result << endl; // prints 100

    return 0;
}