
# Problem link ===>>  https://leetcode.com/problems/permutations-ii/description/
# submission link == =>> https://leetcode.com/problems/permutations-ii/submissions/1493413743/


from typing import List
class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        """
        Generates all unique permutations of a list containing duplicates.
        """
        result = []
        nums.sort()  # Crucial for handling duplicates efficiently

        def backtrack(current_permutation, remaining_nums):
            if not remaining_nums:
                result.append(current_permutation.copy())
                return

            for i in range(len(remaining_nums)):
                # Skip duplicates: If the current element is the same as the previous one
                # AND the previous one hasn't been used yet in the current permutation, skip it.
                if i > 0 and remaining_nums[i] == remaining_nums[i - 1]:
                    continue

                backtrack(
                    current_permutation + [remaining_nums[i]],
                    remaining_nums[:i] + remaining_nums[i + 1:],
                )

        backtrack([], nums)
        return result


if __name__ == "__main__":
    sol = Solution()
    nums = [1, 1, 2]
    unique_perms = sol.permuteUnique(nums)
    print("Unique permutations:")
    for perm in unique_perms:
        print(perm)

    nums = [1, 2, 3]
    unique_perms = sol.permuteUnique(nums)
    print("Unique permutations:")
    for perm in unique_perms:
        print(perm)
