
# Problem link ===>>  https://leetcode.com/problems/permutation-sequence/description/
# submission link == =>> https://leetcode.com/problems/permutation-sequence/submissions/1528724720/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        from math import factorial

        fact = factorial(n - 1)
        nums = list(range(1, n + 1))
        k -= 1  # Convert to 0-based index
        ans = []

        while nums:
            index = k // fact
            ans.append(str(nums[index]))
            nums.pop(index)

            if not nums:
                break

            k %= fact
            fact //= len(nums)

        return "".join(ans)



if __name__ == "__main__":
    solution = Solution()
