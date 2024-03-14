# Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a 
# Unix-style file system, convert it to the simplified canonical path.

# In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the 
# directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. 
# For this problem, any other format of periods such as '...' are treated as file/directory names.

# The canonical path should have the following format:

# The path starts with a single slash '/'.
# Any two directories are separated by a single slash '/'.
# The path does not end with a trailing '/'.
# The path only contains the directories on the path from the root directory to the target file or directory 
# (i.e., no period '.' or double period '..')
# Return the simplified canonical path.

# Input: path = "/home/"
# Output: "/home"
# Explanation: Note that there is no trailing slash after the last directory name.

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
