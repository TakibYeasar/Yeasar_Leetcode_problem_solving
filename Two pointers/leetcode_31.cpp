
// Problem Link ====>>https://leetcode.com/problems/next-permutation/description/

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