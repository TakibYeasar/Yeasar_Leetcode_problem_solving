# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

class Solution:
    def generateParenthesis(self, n):
        if n == 0:
            return [""]

        result = []
        self.generateParenthesisHelper(result, "", 0, 0, n)

        return result

    def generateParenthesisHelper(self, result, current, opening, closing, n):
        if closing > opening or opening > n:
            return

        if opening == n and closing == n:
            result.append(current)
            return

        current += "("
        self.generateParenthesisHelper(
            result, current, opening + 1, closing, n)
        current = current[:-1]

        current += ")"
        self.generateParenthesisHelper(
            result, current, opening, closing + 1, n)
        current = current[:-1]
