# The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
# countAndSay(1) = "1"
# countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), 
# which is then converted into a different digit string.
# To determine how you "say" a digit string, split it into the minimal number of substrings such that each 
# substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. 
# Finally, concatenate every said digit.

class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        if n == 2:
            return "11"
        
        prev = "11"
        for _ in range(2, n):
            curr = ""
            count = 1
            for i in range(len(prev)):
                if i == 0 or prev[i] == prev[i-1]:
                    count += 1
                else:
                    curr += str(count) + prev[i-1]
                    count = 1
            curr += str(count) + prev[-1]
            prev = curr
        return prev

# Example usage
solution = Solution()
result = solution.countAndSay(4)
print(f"The 4th term in the count-and-say sequence is: {result}")
