# A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

# For example, for arr = [1,2,3], the following are all the permutations of arr: 
# [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
# The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
# More formally, if all the permutations of the array are sorted in one container according to their 
# lexicographical order, then the next permutation of that array is the permutation that follows it in the 
# sorted container. If such arrangement is not possible, the array must be rearranged as the lowest 
# possible order (i.e., sorted in ascending order).

# For example, the next permutation of arr = [1,2,3] is [1,3,2].
# Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
# While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
# Given an array of integers nums, find the next permutation of nums.

# The replacement must be in place and use only constant extra memory.

from collections import Counter


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        word_counts = Counter(words)  # Dictionary of word frequencies
        total_words = len(words)
        word_len = len(words[0])
        window_size = total_words * word_len  # Total length of concatenated words

        ans = []
        for i in range(len(s) - window_size + 1):
            seen_words = Counter()  # Words seen inside the current window
            words_seen = 0

            # Pre-compute word offsets and early exit check
            j = i
            remaining_words = total_words
            while j < i + window_size and remaining_words > 0:
                sub_str = s[j:j + word_len]
                if sub_str in word_counts:
                    if seen_words[sub_str] + 1 > word_counts[sub_str]:
                        break  # Exceeded allowed frequency, early exit
                    seen_words[sub_str] += 1
                    j += word_len
                    remaining_words -= 1
                else:
                    break  # Unknown word, stop matching

            if remaining_words == 0:  # Found all words in window
                ans.append(i)

        return ans


# Example usage
s = "barfoothefoobarman"
words = ["foo", "bar"]

sol = Solution()
result = sol.findSubstring(s, words)

for index in result:
    print(f"Starting index: {index}")
