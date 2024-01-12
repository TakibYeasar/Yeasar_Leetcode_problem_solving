# You are given a string s and an array of strings words.All the strings of words are of the same length.
# A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
# For example, if words = [ "ab", "cd", "ef" ], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and"efcdab" 
# are all concatenated strings."acdbef" is not a concatenated substring because it is not the concatenation 
# of any permutation of words.Return the starting indices of all the concatenated substrings in s.
# You can return the answer in any order.

from collections import Counter, defaultdict


class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        dict = Counter(words)  # Count word frequencies
        n = len(s)
        m = len(words[0])
        w = len(words)
        res = []

        for k in range(m):  # Iterate through possible starting positions
            seen = defaultdict(int)  # Track seen words in current window
            currLen = 0
            left = k
            for i in range(left, n - m + 1, m):  # Slide window with stride m
                temp = s[i:i + m]
                if temp not in dict:
                    seen.clear()
                    currLen = 0
                    left = i + m
                else:
                    seen[temp] += 1
                    currLen += 1
                    while seen[temp] > dict[temp]:
                        temp1 = s[left:left + m]
                        seen[temp1] -= 1
                        currLen -= 1
                        left += m
                    if currLen == w:
                        res.append(left)
                        seen[s[left:left + m]] -= 1
                        currLen -= 1
                        left += m
        return res


if __name__ == "__main__":
    s = "barfoothefoobarman"
    words = ["foo", "bar"]

    solution = Solution()
    result = solution.findSubstring(s, words)

    print("Starting indices of substrings containing all words:", result)
