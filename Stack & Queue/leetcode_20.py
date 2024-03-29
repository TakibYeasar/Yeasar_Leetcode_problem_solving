
# Problem Link ====>>https://leetcode.com/problems/valid-parentheses/description/

def isValid(s):
    closing_brackets = {')': '(', '}': '{', ']': '['}
    stack = []

    for char in s:
        if char in closing_brackets:
            if not stack or stack[-1] != closing_brackets[char]:
                return False
            stack.pop()
        else:
            stack.append(char)

    return not stack


if __name__ == "__main__":
    s = "()"
    isValid = isValid(s)

    if isValid:
        print(f"The string {s} is valid.")
    else:
        print(f"The string {s} is not valid.")
