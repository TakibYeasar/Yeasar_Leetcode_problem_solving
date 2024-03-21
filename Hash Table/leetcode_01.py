
# Problem Link ====>> https://leetcode.com/problems/two-sum/description/



# Solution 2: (Two-pass Hash Table)
def twoSum(nums, target):
    num_map = {}
    n = len(nums)

    # Build the hash table
    for i in range(n):
        num_map[nums[i]] = i

    # Find the complement
    for i in range(n):
        complement = target - nums[i]
        if complement in num_map and num_map[complement] != i:
            return [i, num_map[complement]]

    return []  # No solution found


# Create vector of integers for nums
nums = [2, 7, 11, 15]

# Target value
target = 9

# Find the pair of indices that sum up to target
indices = twoSum(nums, target)

# Check if a solution was found
if not indices:
    print("No solution found.")
else:
    print("Indices of the two numbers that sum up to target:",
          indices[0], ",", indices[1])



# Solution 3: (One-pass Hash Table)
def twoSum(nums, target):
    num_map = {}
    n = len(nums)

    # Build the hash table
    for i in range(n):
        num_map[nums[i]] = i

    # Find the complement
    for i in range(n):
        complement = target - nums[i]
        if complement in num_map and num_map[complement] != i:
            return [i, num_map[complement]]

    return []  # No solution found


# Create vector of integers for nums
nums = [2, 7, 11, 15]

# Target value
target = 9

# Find the pair of indices that sum up to target
indices = twoSum(nums, target)

# Check if a solution was found
if not indices:
    print("No solution found.")
else:
    print("Indices of the two numbers that sum up to target:",
          indices[0], ",", indices[1])
