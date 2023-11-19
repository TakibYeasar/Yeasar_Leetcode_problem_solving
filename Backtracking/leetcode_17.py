# Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number
# could represent.Return the answer in any order. A mapping of digits to
# letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        phone_map = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(current: str, digits: str, result: List[str]):
            if not digits:
                result.append(current)
                return

            digit = digits[0]
            letters = phone_map[digit]

            for letter in letters:
                backtrack(current + letter, digits[1:], result)

        result = []
        backtrack("", digits, result)
        return result
