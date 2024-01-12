// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: 
// [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
// More formally, if all the permutations of the array are sorted in one container according to their 
// lexicographical order, then the next permutation of that array is the permutation that follows it in the 
// sorted container. If such arrangement is not possible, the array must be rearranged as the lowest 
// possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> wordCounts; // Frequency of each word
        int totalWords = words.size();
        int wordLen = words[0].size();
        int windowSize = totalWords * wordLen; // Total length of concatenated words

        for (const string &word : words)
        {
            ++wordCounts[word]; // Count word frequency
        }

        vector<int> ans;
        for (int i = 0; i <= (int)s.size() - windowSize; ++i)
        {
            unordered_map<string, int> seenWords; // Words seen inside the current window
            int wordsSeen = 0;                    // Number of words seen

            // Pre-compute word offsets and early exit check
            int j = i;
            int remainingWords = totalWords;
            while (j < i + windowSize && remainingWords > 0)
            {
                string subStr = s.substr(j, wordLen);
                if (wordCounts.count(subStr) > 0)
                {
                    if (++seenWords[subStr] > wordCounts[subStr])
                    {
                        break; // Exceeded allowed frequency, early exit
                    }
                    j += wordLen;
                    remainingWords--;
                }
                else
                {
                    break; // Unknown word, stop matching
                }
            }

            if (remainingWords == 0)
            { // Found all words in window
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{
    // Example usage
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    Solution sol;
    vector<int> result = sol.findSubstring(s, words);

    for (int index : result)
    {
        std::cout << "Starting index: " << index << std::endl;
    }

    return 0;
}