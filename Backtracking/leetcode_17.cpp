// Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number 
// could represent.Return the answer in any order. A mapping of digits to
// letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.

#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    vector<string> letterCombinations(string digits){
        vector<string> result;

        if(digits.empty()){
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

