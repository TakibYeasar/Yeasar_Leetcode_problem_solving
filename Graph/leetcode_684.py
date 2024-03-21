# Problem Link == == >>https://leetcode.com/problems/redundant-connection/description/

class Solution:
    def findRedundantConnection(self, edges: list[list[int]]) -> list[int]:
        n = len(edges)
        graph = [[] for _ in range(n + 1)]  # Adjacency list representation
        visited = [False] * (n + 1)
        cycle = set()
        cycle_start = -1

        # Build the graph from the edges
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        def dfs(cur, par=-1):
            nonlocal cycle_start
            if visited[cur]:
                cycle_start = cur
                return  # Found a cycle by reaching a visited node

            visited[cur] = True
            for child in graph[cur]:
                if child == par:
                    continue  # Skip parent to avoid back-and-forth loop
                if not cycle:
                    dfs(child, cur)
                if cycle_start != -1:
                    # Add current node to cycle set if cycle detected
                    cycle.add(cur)
                if cur == cycle_start:
                    cycle_start = -1
                    return  # Reached the start of the cycle, stop exploration

        # Perform DFS to detect cycles and populate the cycle set
        dfs(1)

        # Find the last edge in the input that has both nodes in the cycle
        for i in range(n - 1, -1, -1):
            if edges[i][0] in cycle and edges[i][1] in cycle:
                return edges[i]

        return []  # No redundant connection found


# Main function for testing
edges = [[1, 2], [1, 3], [2, 3]]
solution = Solution()
result = solution.findRedundantConnection(edges)

if not result:
    print("No redundant connection found.")
else:
    print(f"Redundant connection: {result[0]}, {result[1]}")
