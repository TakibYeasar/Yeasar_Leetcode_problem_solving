# Problem Link ====>>https://leetcode.com/problems/combination-sum-ii/description/

class Solution:
    def __init__(self):
        self.result = []  # List to store unique combinations

    def comsum(self, curr, target, sum, candidates, curInd, n):
        if target == sum:
            self.result.append(curr.copy())  # Append a copy of the combination
            return

        if sum > target:
            return

        for i in range(curInd, n):
            # Avoid duplicates
            if i > curInd and candidates[i] == candidates[i - 1]:
                continue

            sum += candidates[i]
            curr.append(candidates[i])
            self.comsum(curr, target, sum, candidates, i + 1, n)
            sum -= candidates[i]
            curr.pop()

    def combinationSum2(self, candidates, target):
        curr = []  # Temporary list for combinations
        n = len(candidates)
        candidates.sort()  # Sort for duplicate handling
        self.comsum(curr, target, 0, candidates, 0, n)
        return self.result


if __name__ == "__main__":
    candidates = [10, 1, 2, 7, 6, 1, 5]  # Example candidate set
    target = 8  # Example target sum

    solution = Solution()
    combinations = solution.combinationSum2(candidates, target)

    print("All unique combinations that sum up to", target, ":")
    for combination in combinations:
        print(combination)
