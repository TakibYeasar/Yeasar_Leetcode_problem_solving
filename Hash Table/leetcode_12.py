# Problem Link ====>>https://leetcode.com/problems/integer-to-roman/description/
def intToRoman(num):
    values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    symbols = ["M", "CM", "D", "CD", "C", "XC",
               "L", "XL", "X", "IX", "V", "IV", "I"]

    result = ""
    for i in range(len(values)):
        while num >= values[i]:
            result += symbols[i]
            num -= values[i]

    return result


if __name__ == "__main__":
    num = 1994
    romanNumeral = intToRoman(num)

    print(f"The Roman numeral equivalent of {num} is: {romanNumeral}")
