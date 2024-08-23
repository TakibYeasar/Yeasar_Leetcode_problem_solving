
# Problem link ===>>  https://leetcode.com/problems/find-the-number-of-winning-players/description/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        ans = 0
        for i in range(n):
            mp = {}
            for j in range(len(pick)):
                if pick[j][0] == i:
                    mp[pick[j][1]] = mp.get(pick[j][1], 0) + 1
                    if mp[pick[j][1]] > i:
                        ans += 1
                        break
        return ans

def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        pick = []
        for _ in range(m):
            pick.append(list(map(int, input().split())))
        sol = Solution()
        print(sol.winningPlayerCount(n, pick))


if __name__ == "__main__":
    solution = Solution()
