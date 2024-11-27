
// Problem link ===>>  https://leetcode.com/problems/group-anagrams/description/
// submission link ===>> https://leetcode.com/problems/group-anagrams/submissions/1464184682/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagramsMap;

        for (string &s : strs)
        {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            anagramsMap[sortedStr].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &pair : anagramsMap)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);

    for (const auto &group : result)
    {
        cout << "[ ";
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}