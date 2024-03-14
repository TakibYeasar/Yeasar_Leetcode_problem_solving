# There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
# You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
# take course bi first if you want to take course ai.

# For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
# Return true if you can finish all courses. Otherwise, return false.

# Input: numCourses = 2, prerequisites = [[1,0]]
# Output: true
# Explanation: There are a total of 2 courses to take. 
# To take course 1 you should have finished course 0. So it is possible.

from collections import defaultdict
from collections import deque


class Solution:
    def canFinish(self, n: int, prerequisites: list[list[int]]) -> bool:
        if n <= 0:  # Check for invalid number of courses
            return False

        adj = defaultdict(list)  # Use defaultdict for efficiency
        indegree = [0] * n

        # Build adjacency list and calculate indegrees
        for course, prerequisite in prerequisites:
            adj[prerequisite].append(course)
            indegree[course] += 1

        # Find courses with no prerequisites (indegree 0)
        queue = deque()
        for i in range(n):
            if indegree[i] == 0:
                queue.append(i)

        # Topological sorting using BFS
        completed = 0
        while queue:
            course = queue.popleft()
            completed += 1

            # Decrement indegrees of neighbors
            for neighbor in adj[course]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        # Check if all courses were completed (no cycles)
        return completed == n


# Example usage in main function
if __name__ == "__main__":
    num_courses = 2
    # Example dependency: course 1 needs to be completed before course 0
    prerequisites = [[1, 0]]

    solution = Solution()
    can_finish = solution.canFinish(num_courses, prerequisites)

    if can_finish:
        print("The courses can be completed in a valid order.")
    else:
        print("There is a cycle in the prerequisites and the courses cannot be completed.")
