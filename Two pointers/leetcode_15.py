# https://leetcode.com/problems/3sum/description/


def threeSum(nums):
    if len(nums) < 3:
        return []  # Not enough elements to form a triplet

    # Sort the array to make it easier to identify triplets
    nums.sort()

    result = []
    for i in range(len(nums) - 2):
        # Skip duplicate elements
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        left = i + 1
        right = len(nums) - 1

        while left < right:
            sum = nums[i] + nums[left] + nums[right]

            if sum == 0:
                result.append([nums[i], nums[left], nums[right]])

                # Skip duplicate elements
                while left < right and nums[left] == nums[left + 1]:
                    left += 1

                while left < right and nums[right] == nums[right - 1]:
                    right -= 1

                left += 1
                right -= 1
            elif sum < 0:
                left += 1
            else:
                right -= 1

    return result


# Create a vector of integers for nums
nums = [-1, 0, 1, 2, -1, -4]

# Find all unique triplets in the array that sum to zero
triplets = threeSum(nums)

# Print the unique triplets
for triplet in triplets:
    for num in triplet:
        print(num, end=" ")
    print()
