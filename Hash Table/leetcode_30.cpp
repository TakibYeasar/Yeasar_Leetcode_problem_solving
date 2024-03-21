
// Problem Link ====>>https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> dict;
        for (auto &w : words)
            dict[w]++;
        vector<int> res;
        int n = s.length(), m = words[0].length(), w = words.size();

        for (int k = 0; k < m; k++)
        { // O(m)
            unordered_map<string, int> seen;
            int left = k, currLen = 0;
            for (int i = left; i + m <= n; i += m)
            {                                 // 2*O(n/m)
                string temp = s.substr(i, m); // O(m)
                if (!(dict.count(temp)))
                {
                    seen.clear();
                    currLen = 0;
                    left = i + m;
                }
                else
                {
                    seen[temp]++;
                    currLen++;
                    if (seen[temp] > dict[temp])
                    {
                        while (seen[temp] > dict[temp])
                        {
                            string temp1 = s.substr(left, m);
                            seen[temp1]--;
                            currLen--;
                            left += m;
                        }
                    }
                }
                if (currLen == w)
                {
                    res.push_back(left);
                    seen[s.substr(left, m)]--;
                    currLen--;
                    left += m;
                }
            }
        }
        return res;
    }
};

int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    Solution solution;
    vector<int> result = solution.findSubstring(s, words);

    cout << "Starting indices of substrings containing all words: ";
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
