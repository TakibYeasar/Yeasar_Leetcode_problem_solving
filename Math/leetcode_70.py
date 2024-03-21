# Problem Link ====>>https://leetcode.com/problems/climbing-stairs/description/

class Solution:
    def climbStairs(self, n: int) -> int:
        """
        Calculates the number of ways to climb a staircase with `n` steps.

        Args:
            n: The number of steps in the staircase.

        Returns:
            The number of ways to climb the staircase.
        """

        # If the staircase has 1 or 2 steps, there is only 1 way to climb it.
        if n == 1 or n == 2:
            return n

        # Create an array to store the number of ways to climb the staircase up to
        # each step.
        dp = [0] * (n + 1)

        # Initialize the first two steps.
        dp[1] = 1
        dp[2] = 2

        # Calculate the number of ways to climb the staircase up to each step.
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        # Return the number of ways to climb the staircase to the top step.
        return dp[n]

solution = Solution()
n = 5
ways_to_climb = solution.climbStairs(n)

print(ways_to_climb)  # prints 8
