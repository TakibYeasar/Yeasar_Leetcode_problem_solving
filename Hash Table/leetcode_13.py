# Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
#
# Symbol       Value
# I             1
# V             5
# X             10
# L             50
# C             100
# D             500
# M             1000
# For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II.
# The number 27 is written as XXVII, which is XX + V + II.
#
# Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead,
# the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies
#  to the number nine, which is written as IX. There are six instances where subtraction is used:
#
# I can be placed before V (5) and X (10) to make 4 and 9.
# X can be placed before L (50) and C (100) to make 40 and 90.
# C can be placed before D (500) and M (1000) to make 400 and 900.
# Given a roman numeral, convert it to an integer.

def romanToInt(s):
    roman_numeral_map = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }

    integer = 0
    previous_value = 0
    for i in range(len(s) - 1, -1, -1):
        current_numeral = s[i]
        current_value = roman_numeral_map[current_numeral]

        if current_value < previous_value:
            integer -= current_value
        else:
            integer += current_value

        previous_value = current_value

    return integer


if __name__ == "__main__":
    s = "MCMXCIV"
    integer = romanToInt(s)

    print(f"The integer equivalent of the Roman numeral \"{s}\" is: {integer}")




class Solution:
    def romanToInt(self, s):
        roman_numeral_map = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }

        result = 0
        previous_value = 0
        for i in range(len(s) - 1, -1, -1):
            current_numeral = s[i]
            current_value = roman_numeral_map[current_numeral]

            if current_value < previous_value:
                result -= current_value
            else:
                result += current_value

            previous_value = current_value

        return result


if __name__ == "__main__":
    s = "MCMXCIV"
    solution = Solution()
    integer = solution.romanToInt(s)

    print(f"The integer equivalent of the Roman numeral \"{s}\" is: {integer}")
