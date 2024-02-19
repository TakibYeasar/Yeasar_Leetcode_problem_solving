# Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of 
# unique values from 1 to n. Return the answer in any order.

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Approach Recursion

# class Solution:
#     def generateTrees(self, n: int):
#         def generate_trees(start, end):
#             if start > end:
#                 return [None,]

#             all_trees = []
#             for i in range(start, end + 1):
#                 left_trees = generate_trees(start, i - 1)
#                 right_trees = generate_trees(i + 1, end)

#                 for l in left_trees:
#                     for r in right_trees:
#                         current_tree = TreeNode(i)
#                         current_tree.left = l
#                         current_tree.right = r
#                         all_trees.append(current_tree)

#             return all_trees

#         return generate_trees(1, n) if n else []


# Dynamic Programming

class Solution:
    def generateTrees(self, n: int):
        if n == 0:
            return []

        dp = [[] for _ in range(n + 1)]
        dp[0].append(None)
        for nodes in range(1, n + 1):
            for root in range(1, nodes + 1):
                for left_tree in dp[root - 1]:
                    for right_tree in dp[nodes - root]:
                        root_node = TreeNode(root)
                        root_node.left = left_tree
                        root_node.right = self.clone(right_tree, root)
                        dp[nodes].append(root_node)
        return dp[n]

    def clone(self, n: TreeNode, offset: int) -> TreeNode:
        if n:
            node = TreeNode(n.val + offset)
            node.left = self.clone(n.left, offset)
            node.right = self.clone(n.right, offset)
            return node
        return None
