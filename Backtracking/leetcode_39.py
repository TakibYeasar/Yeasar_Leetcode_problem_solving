# Given an array of distinct integers candidates and a target integer target, return a list of all unique 
# combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

# The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
# frequency of at least one of the chosen numbers is different.

# The test cases are generated such that the number of unique combinations that sum up to target is less than 
# 150 combinations for the given input.

class Solution:
    def __init__(self):
        self.ans = []  # 2D list to store combinations

    def solve(self, i, arr, temp, target):
        if target == 0:
            self.ans.append(temp.copy())  # Append a copy of the combination
            return

        if target < 0 or i == len(arr):
            return

        # Exclude the current element
        self.solve(i + 1, arr, temp, target)

        # Include the current element
        temp.append(arr[i])
        self.solve(i, arr, temp, target - arr[i])
        temp.pop()  # Backtrack

    def combinationSum(self, arr, target):
        self.ans.clear()  # Clear previous results
        temp = []  # Temporary list for combinations
        self.solve(0, arr, temp, target)
        return self.ans

if __name__ == "__main__":
    arr = [2, 3, 6, 7]
    target = 7

    solution = Solution()
    combinations = solution.combinationSum(arr, target)

    print("All combinations that sum up to", target, ":")
    for combination in combinations:
        print(combination)
