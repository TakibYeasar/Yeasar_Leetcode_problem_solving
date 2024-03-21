# Problem Link ====>>https://leetcode.com/problems/generate-parentheses/description/

class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return ['']

        result = []
        self.generateParenthesisHelper(result, '', 0, 0, n)
        return result

    def generateParenthesisHelper(self, result, current: str, opening: int, closing: int, n: int):
        if opening > closing or opening > n:
            return

        if opening == n and closing == n:
            result.append(current)
            return

        current += '('
        self.generateParenthesisHelper(
            result, current, opening + 1, closing, n)
        current = current[:-1]

        current += ')'
        self.generateParenthesisHelper(
            result, current, opening, closing + 1, n)
        current = current[:-1]


n = 3
solution = Solution()
parentheses = solution.generateParenthesis(n)

for parenthesis in parentheses:
    print(parenthesis)
