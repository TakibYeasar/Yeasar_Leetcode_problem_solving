
// Problem Link ====>> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> lastIndex(256, -1);
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (lastIndex[s[i]] >= start)
            {
                start = max(start, lastIndex[s[i]] + 1);
            }
            lastIndex[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution solution;
    int result = solution.lengthOfLongestSubstring(s);
    cout << result << endl;

    return 0;
}


// ===================>>> Approach 1 -

#include <iostream>
#include <vector>
using namespace std;
#include <unordered_set>
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (charSet.count(s[right]) == 0)
            {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            }
            else
            {
                while (charSet.count(s[right]))
                {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }

        return maxLength;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution solution;

    int maxLength = solution.lengthOfLongestSubstring(s);

    cout << "The length of the longest substring without repeating characters in \"" << s << "\" is: " << maxLength << endl;

    return 0;
}

//===================>>> Approach 2 - Unordered Map

#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> charMap;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (charMap.count(s[right]) == 0 || charMap[s[right]] < left)
            {
                charMap[s[right]] = right;
                maxLength = max(maxLength, right - left + 1);
            }
            else
            {
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }

        return maxLength;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution solution;

    int maxLength = solution.lengthOfLongestSubstring(s);

    cout << "The length of the longest substring without repeating characters in \"" << s << "\" is: " << maxLength << endl;

    return 0;
}

//===================>>> Approach 3 - Integer Array

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLength = 0;
        vector<int> charIndex(128, -1);
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            if (charIndex[s[right]] >= left)
            {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution solution;

    int maxLength = solution.lengthOfLongestSubstring(s);

    cout << "The length of the longest substring without repeating characters in \"" << s << "\" is: " << maxLength << endl;

    return 0;
}