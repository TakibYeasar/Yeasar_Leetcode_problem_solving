
# Problem link ===>>  https://leetcode.com/problems/permutations/description/
# submission link == =>> https://leetcode.com/problems/permutations/submissions/1493387722/

class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        def backtrack(start):
            if start == len(nums):
                # Append a copy of the current permutation
                result.append(nums.copy())
                return

            for i in range(start, len(nums)):
                nums[start], nums[i] = nums[i], nums[start]  # Swap elements
                backtrack(start + 1)  # Recursive call
                # Backtrack (undo swap)
                nums[start], nums[i] = nums[i], nums[start]

        result = []
        backtrack(0)
        return result


# Example usage
if __name__ == "__main__":
    solution = Solution()
    nums = [1, 2, 3]
    permutations = solution.permute(nums)

    print("All permutations:")
    for perm in permutations:
        print(perm)
