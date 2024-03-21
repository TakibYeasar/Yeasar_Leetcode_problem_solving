
# Problem Link == == >> https://leetcode.com/problems/clone-graph/description/

from collections import defaultdict


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: Node) -> Node:
        if not node:
            return None

        visited = {}
        return self.dfs(node, visited)

    def dfs(self, node: Node, visited: dict[Node, Node]) -> Node:
        if node in visited:
            return visited[node]

        clone = Node(node.val)
        visited[node] = clone

        for neighbor in node.neighbors:
            clone.neighbors.append(self.dfs(neighbor, visited))

        return clone


# Sample usage in main function
if __name__ == "__main__":
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)

    node1.neighbors.append(node2)
    node1.neighbors.append(node3)
    node2.neighbors.append(node1)
    node2.neighbors.append(node3)
    node3.neighbors.append(node1)
    node3.neighbors.append(node2)

    solution = Solution()
    cloned_graph = solution.cloneGraph(node1)

    # You can now use the cloned_graph here
    print(f"Cloned graph node1 value: {cloned_graph.val}")  # Example usage
