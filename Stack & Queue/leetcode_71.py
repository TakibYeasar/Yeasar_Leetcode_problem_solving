# Problem Link ====>>https://leetcode.com/problems/simplify-path/description/

class Solution:
    def simplify_path(self, path: str) -> str:

        stack = []
        res = ""

        for char in path:
            if char == '/':
                continue

            temp = ""
            while char != '/' and path.index(char) < len(path):
                temp += char
                char = path[path.index(char) + 1]

            if temp == ".":
                continue
            elif temp == "..":
                if stack:
                    stack.pop()
            else:
                stack.append(temp)

        while stack:
            res = "/" + stack.pop() + res

        return "/" if not res else res

if __name__ == "__main__":
    input_path = input("Enter a path to simplify: ")
    solution = Solution()
    simplified_path = solution.simplify_path(input_path)
    print("Simplified path:", simplified_path)
