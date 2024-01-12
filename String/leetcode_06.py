# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
# (you may want to display this pattern in a fixed font for better legibility)
#
# P   A   H   N
# A P L S I I G
# Y   I   R
# And then read line by line: "PAHNAPLSIIGYIR"

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s  # No change needed for a single row.

        rows = [[] for _ in range(min(numRows, len(s)))]
        currentRow = 0
        goingDown = False

        for char in s:
            rows[currentRow].append(char)

            if currentRow == 0 or currentRow == numRows - 1:
                goingDown = not goingDown

            currentRow += 1 if goingDown else -1

        result = ""
        for row in rows:
            result += "".join(row)

        return result


if __name__ == "__main__":
    s = "PAYPALISHIRING"
    numRows = 3

    solution = Solution()
    convertedString = solution.convert(s, numRows)

    print(f"The converted string is: {convertedString}")
