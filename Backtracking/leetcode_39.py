# Problem Link ====>>https://leetcode.com/problems/combination-sum/description/

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
