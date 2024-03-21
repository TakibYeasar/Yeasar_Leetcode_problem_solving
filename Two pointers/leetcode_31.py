# Problem Link ====>>https://leetcode.com/problems/next-permutation/description/

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
