
# Problem link ===>>  https://leetcode.com/problems/long-pressed-name/description/
# submission link == =>> https://leetcode.com/problems/long-pressed-name/submissions/1593315152/

from typing import List

class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        n, t = len(name), len(typed)
        p1 = p2 = 0

        while True:
            if p1 >= n and p2 >= t:
                return True

            if p1 >= n:
                if typed[p2] == name[-1]:
                    p2 += 1
                    continue
                else:
                    return False

            if p2 >= t:
                return False

            if name[p1] == typed[p2]:
                p1 += 1
                p2 += 1
            else:
                if p1 == 0:
                    return False
                elif name[p1 - 1] == typed[p2]:
                    p2 += 1
                else:
                    return False


if __name__ == "__main__":
    solution = Solution()
