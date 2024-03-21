# Problem Link ====>>https://leetcode.com/problems/roman-to-integer/description/

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
