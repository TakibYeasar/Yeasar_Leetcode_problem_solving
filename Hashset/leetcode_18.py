# Problem Link ====>>https://leetcode.com/problems/4sum/description/

# ===================>>>✔️ Solution 1 : HashSet
def fourSum(nums, target):
    seen = set()
    ans_set = set()
    n = len(nums)

    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                lastNumber = target - (nums[i] + nums[j] + nums[k])

                if lastNumber in seen:
                    ans_set.add(
                        frozenset((nums[i], nums[j], nums[k], lastNumber)))

        seen.add(nums[i])

    ans = []
    for el in ans_set:
        ans.append(list(el))

    return ans


if __name__ == "__main__":
    nums = [1, 0, -1, 0, -2, 2]
    target = 0

    quadruplets = fourSum(nums, target)

    for quadruplet in quadruplets:
        for num in quadruplet:
            print(num, end=" ")
        print()
