# Problem Link ====>>https://leetcode.com/problems/longest-common-prefix/description/

class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        prefix = ""

        # Find the shortest string in the list.
        min_length = len(strs[0])
        for str in strs:
            min_length = min(min_length, len(str))

        # Iterate over the characters of the shortest string and check if they match
        # the corresponding characters of all other strings. If they do, add the character
        # to the prefix. Otherwise, break out of the loop.
        for i in range(min_length):
            char = strs[0][i]
            all_match = True
            for j in range(1, len(strs)):
                if strs[j][i] != char:
                    all_match = False
                    break

            if all_match:
                prefix += char
            else:
                break

        return prefix


if __name__ == "__main__":
    strs = ["flower", "flow", "flight"]

    solution = Solution()
    prefix = solution.longestCommonPrefix(strs)

    print(f"The longest common prefix of the given strings is: {prefix}")
