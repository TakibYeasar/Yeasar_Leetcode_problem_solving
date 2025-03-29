
# Problem link ===>>  https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
# submission link == =>> https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/1590274065/

from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        cnt_p = [0] * 26
        cnt_w = [0] * 26

        for c in p:
            # Used ord() to get character ASCII values
            cnt_p[ord(c) - ord('a')] += 1

        k = len(p)
        n = len(s)

        # Initialize the first window
        for i in range(k):
            if i < n:  # To handle case when k > n
                cnt_w[ord(s[i]) - ord('a')] += 1

        result = []
        for i in range(n):
            # Check if current window matches
            if cnt_p == cnt_w:
                result.append(i)

            # Move the window
            cnt_w[ord(s[i]) - ord('a')] -= 1
            if i + k < n:
                cnt_w[ord(s[i + k]) - ord('a')] += 1
            else:
                break

        return result


if __name__ == "__main__":
    solution = Solution()
