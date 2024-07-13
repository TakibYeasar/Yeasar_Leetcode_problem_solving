
# Problem link ===>>  https://leetcode.com/problems/range-sum-query-immutable/

class NumArray:

    def __init__(self, nums):
        self.pref = self.generate_prefix_sum(nums)

    def generate_prefix_sum(self, nums):
        n = len(nums)
        pref = [0] * (n + 1)
        for i in range(n):
            pref[i + 1] = pref[i] + nums[i]
        return pref

    def sum_range(self, left, right):
        return self.pref[right + 1] - self.pref[left]


def main():
    nums = [1, 2, 3, 4, 5]  # Example list of numbers
    num_array = NumArray(nums)

    # Test cases
    # Sum of elements from index 0 to 2: 1 + 2 + 3 = 6
    print(num_array.sum_range(0, 2))
    # Sum of elements from index 1 to 3: 2 + 3 + 4 = 9
    print(num_array.sum_range(1, 3))
    # Sum of elements from index 2 to 4: 3 + 4 + 5 = 12
    print(num_array.sum_range(2, 4))


if __name__ == "__main__":
    main()

