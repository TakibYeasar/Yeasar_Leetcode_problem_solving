# Problem Link == == >>https://leetcode.com/problems/course-schedule-ii/description/

# ============> Solution - I (Topological Sort - BFS)
from collections import defaultdict
from collections import deque


class Solution:
    def findOrder(self, n: int, prerequisites: list[list[int]]) -> list[int]:
        if n <= 0:  # Check for invalid number of courses
            return []

        # Build the adjacency list and calculate indegrees
        graph = defaultdict(list)
        indegree = [0] * n
        for course, prerequisite in prerequisites:
            graph[prerequisite].append(course)
            indegree[course] += 1

        # Find courses with no prerequisites (indegree 0)
        queue = deque()
        for i in range(n):
            if indegree[i] == 0:
                queue.append(i)

        # Topological sorting using BFS
        completed_courses = 0
        course_order = []
        while queue:
            course = queue.popleft()
            completed_courses += 1
            course_order.append(course)

            # Decrement indegrees of neighbors and add them to the queue if they become available
            for next_course in graph[course]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    queue.append(next_course)

        # Check if all courses were completed (no cycles)
        return course_order if completed_courses == n else []


# Example usage in main function
if __name__ == "__main__":
    num_courses = 4
    prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]  # Sample prerequisites

    solution = Solution()
    course_order = solution.findOrder(num_courses, prerequisites)

    if course_order:
        print("Valid course order:", course_order)
    else:
        print("There is a cycle in the prerequisites, no valid order exists.")


# ===========>  Solution - II (Topological Sort - DFS)


class Solution:
    def findOrder(self, n: int, prerequisites: list[list[int]]) -> list[int]:

        if n <= 0:  # Check for invalid number of courses
            return []

        graph = defaultdict(list)
        indegree = [0] * n
        for course, prerequisite in prerequisites:
            graph[prerequisite].append(course)
            indegree[course] += 1

        topological_order = []
        visited = [0] * n  # 0 - unvisited, 1 - exploring, 2 - visited

        def dfs(course):
            if visited[course] == 1:
                return False  # Cycle detected

            visited[course] = 1  # Mark as exploring

            for next_course in graph[course]:
                if visited[next_course] != 2:
                    if not dfs(next_course):
                        return False

            visited[course] = 2  # Mark as visited
            # Add after exploring all neighbors
            topological_order.append(course)
            return True

        for i in range(n):
            # Start DFS from nodes with no prerequisites
            if indegree[i] == 0 and not dfs(i):
                return []  # Cycle detected

        return topological_order


# Example usage in main function
if __name__ == "__main__":
    num_courses = 4
    prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]  # Sample prerequisites

    solution = Solution()
    course_order = solution.findOrder(num_courses, prerequisites)

    if course_order:
        print("Valid course order:", course_order)
    else:
        print("There is a cycle in the prerequisites, no valid order exists.")
