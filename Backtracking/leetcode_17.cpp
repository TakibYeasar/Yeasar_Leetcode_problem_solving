
// Problem Link ====>>https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;

        if (digits.empty())
        {
            return result;
        }

        unordered_map<char, string> mappings = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        string current;
        backtrack(mappings, digits, 0, current, result);
        return result;
    }

private:
    void backtrack(const unordered_map<char, string> &mappings, const string &digits, int index, string &current, vector<string> &result)
    {
        if (index == digits.length())
        {
            result.push_back(current);
            return;
        }

        const string &letters = mappings.at(digits[index]);
        for (char letter : letters)
        {
            current.push_back(letter);
            backtrack(mappings, digits, index + 1, current, result);
            current.pop_back();
        }
    }
};

int main()
{
    string digits = "23";
    Solution solution;
    vector<string> combinations = solution.letterCombinations(digits);

    cout << "Letter combinations of phone number " << digits << ":" << endl;
    for (string combination : combinations)
    {
        cout << combination << endl;
    }

    return 0;
}
