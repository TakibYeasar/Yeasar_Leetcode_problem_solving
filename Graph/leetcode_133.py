
# Given a reference of a node in a connected undirected graph.
# Return a deep copy (clone) of the graph.
# Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

# class Node {
#     public int val;
#     public List<Node> neighbors;
# }
 

# Test case format:
# For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node 
# with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

# An adjacency list is a collection of unordered lists used to represent a finite graph. 
# Each list describes the set of neighbors of a node in the graph.

# The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

# Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
# Output: [[2,4],[1,3],[2,4],[1,3]]
# Explanation: There are 4 nodes in the graph.
# 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
# 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
# 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
# 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

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
