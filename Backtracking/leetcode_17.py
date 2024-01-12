# Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number
# could represent.Return the answer in any order. A mapping of digits to
# letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.

def letterCombinations(digits):
    if not digits:
        return []

    mappings = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz"
    }

    result = []
    current = []
    backtrack(mappings, digits, 0, current, result)
    return result


def backtrack(mappings, digits, index, current, result):
    if index == len(digits):
        result.append("".join(current))
        return

    letters = mappings[digits[index]]
    for letter in letters:
        current.append(letter)
        backtrack(mappings, digits, index + 1, current, result)
        current.pop()


digits = "23"
combinations = letterCombinations(digits)
print("Letter combinations of phone number", digits, ":")
for combination in combinations:
    print(combination)
