// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if
// needle is not part of haystack.

#include <iostream>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        for (int i = 0; i < haystack.length(); i++)
        {
            if (haystack[i] == needle[0])
            {
                int i1 = i + 1;
                int j = 1;
                while (haystack[i1] && needle[j])
                {
                    if (haystack[i1] != needle[j])
                        break;
                    i1++;
                    j++;
                }
                if (j == needle.length())
                    return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    string haystack = "Hello, world!";
    string needle = "world";
    int index = s.strStr(haystack, needle);

    cout << index << endl; // prints 7

    return 0;
}