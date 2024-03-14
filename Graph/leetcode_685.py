# In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) 
# for which all other nodes are descendants of this node, plus every node has exactly one parent, 
# except for the root node which has no parents.

# The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), 
# with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was 
# not an edge that already existed.

# The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a 
# directed edge connecting nodes ui and vi, where ui is a parent of child vi.

# Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are 
# multiple answers, return the answer that occurs last in the given 2D-array.

# Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
# Output: [4,1]

# Constraints:

# n == edges.length
# 3 <= n <= 1000
# edges[i].length == 2
# 1 <= ui, vi <= n
# ui != vi

class Solution:
    def findRedundantDirectedConnection(self, edges: list[list[int]]) -> list[int]:
        n = len(edges)
        parent = [-1] * (n + 1)
        in_degree = [-1] * (n + 1)
        e1, e2 = -1, -1

        for i in range(n):
            if in_degree[edges[i][1]] != -1:  # indegree 2
                e2 = in_degree[edges[i][1]]  # first edge causing indegree 2
                e1 = i  # second edge causing indegree 2
                break
            in_degree[edges[i][1]] = i

        for i in range(n):
            if i == e1:
                continue  # ignore edge causing indegree 2

            if not self.union_by_weight(edges[i][0], edges[i][1], parent):  # cycle is present
                if e1 != -1:
                    return edges[e2]  # indegree 2, wrong edge ignored
                else:
                    return edges[i]  # indegree 1, remove edge causing cycle

        return edges[e1] if e1 != -1 else []  # return empty list if no indegree 2

    def find(self, u, parent):
        if parent[u] < 0:
            return u
        parent[u] = self.find(parent[u], parent)
        return parent[u]

    def union_by_weight(self, u, v, parent):
        pu = self.find(u, parent)
        pv = self.find(v, parent)

        if pu == pv:
            return False  # cycle detected

        if parent[pu] < parent[pv]:
            parent[pu] += parent[pv]
            parent[pv] = pu
        else:
            parent[pv] += parent[pu]
            parent[pu] = pv
        return True


edges = [[1, 2], [1, 3], [2, 3]]
solution = Solution()
result = solution.findRedundantDirectedConnection(edges)

if not result:
    print("No redundant connection found.")
else:
    print(f"Redundant connection: {result[0]}, {result[1]}")
