// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";

        // Find the shortest string in the vector.
        int min_length = INT_MAX;
        for (string str : strs)
        {
            min_length = min(min_length, (int)str.length());
        }

        // Iterate over the characters of the shortest string and check if they match
        // the corresponding characters of all other strings. If they do, add the character
        // to the prefix. Otherwise, break out of the loop.
        for (int i = 0; i < min_length; i++)
        {
            char c = strs[0][i];
            bool all_match = true;
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != c)
                {
                    all_match = false;
                    break;
                }
            }

            if (all_match)
            {
                prefix += c;
            }
            else
            {
                break;
            }
        }

        return prefix;
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    Solution solution;
    string prefix = solution.longestCommonPrefix(strs);

    cout << "The longest common prefix of the given strings is: " << prefix << endl;

    return 0;
}