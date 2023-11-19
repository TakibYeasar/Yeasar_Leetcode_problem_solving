// Given a string s, find the length of the longest substring without repeating characters.

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

// Intuition
// The intuition behind the 3 solutions is to iteratively find the longest substring without repeating characters by maintaining 
// a sliding window approach.We use two
// pointers(left and right) to represent the boundaries of the current substring.As we iterate through the string,
// we update the pointers and adjust the window to accommodate new unique characters and eliminate repeating characters.

// ===================>>> Approach 1 -
// Set
// We use a set(charSet)
// to keep track of unique characters in the current substring.We maintain two pointers, left and right, to represent the
// boundaries of the current substring.The maxLength variable keeps track of the length of the longest substring encountered so far.
// We iterate through the string using the right pointer.If the current character is not in the set(charSet), it means we have a new
// unique character.We insert the character into the set and update the maxLength if necessary.If the character is already present
// in the set, it indicates a repeating character within the current substring.In this case, we move the left pointer forward,
// removing characters from the set until the repeating character is no longer present.We insert the current character into the
// set and continue the iteration.Finally, we return the maxLength as the length of the longest substring without repeating characters.

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

//===================>>> Approach 2 - Unordered Map
// We improve upon the first solution by using an unordered map(charMap)
// instead of a set.The map stores characters as keys and their indices as values.We still maintain the left and right pointers
// and the maxLength variable.We iterate through the string using the right pointer.If the current character is not in the map or
//  its index is less than left, it means it is a new unique character.6 We update the charMap with the character's index and
//  update the maxLength if necessary. If the character is repeating within the current substring, we move the left pointer to
//  the next position after the last occurrence of the character.We update the index of the current character in the charMap and
//  continue the iteration.At the end, we return the maxLength as the length of the longest substring without repeating characters.

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

//===================>>> Approach 3 - Integer Array
// This solution uses an integer array charIndex to store the indices of characters.
// We eliminate the need for an unordered map by utilizing the array.
// The maxLength, left, and right pointers are still present.
// We iterate through the string using the right pointer.
// We check if the current character has occurred within the current substring by comparing its index in charIndex with left.
// If the character has occurred, we move the left pointer to the next position after the last occurrence of the character.
// We update the index of the current character in charIndex.
// At each step, we update the maxLength by calculating the length of the current substring.
// We continue the iteration until reaching the end of the string.
// Finally, we return the maxLength as the length of the longest substring without repeating characters.

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