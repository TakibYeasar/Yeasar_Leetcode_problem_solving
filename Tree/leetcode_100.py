# Given the roots of two binary trees p and q, write a function to check if they are the same or not.
# Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
# Input: p = [1,2,1], q = [1,1,2]
# Output: false

# Constraints:
# The number of nodes in both trees is in the range [0, 100].
# -104 <= Node.val <= 104

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            # Both trees are empty
            return True
        elif not p or not q:
            # One tree is empty, the other is not
            return False
        else:
            # Compare node values and recursively check left and right subtrees
            return p.val == q.val and \
                self.isSameTree(p.left, q.left) and \
                self.isSameTree(p.right, q.right)


# Example usage
p = TreeNode(1)
p.left = TreeNode(2)
p.right = TreeNode(1)

q = TreeNode(1)
q.left = TreeNode(1)
q.right = TreeNode(2)

sol = Solution()
print("true" if sol.isSameTree(p, q) else "false")
