// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non - space characters only.

#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = 0;
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        while (i >= 0 && s[i] != ' ')
        {
            len++;
            i--;
        }
        return len;
    }
};

int main()
{
    Solution s;
    string str = "Hello World";
    int len = s.lengthOfLastWord(str);
    cout << len << endl; // prints 5

    return 0;
}