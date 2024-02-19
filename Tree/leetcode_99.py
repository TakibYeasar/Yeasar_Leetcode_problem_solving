# You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
# Recover the tree without changing its structure.

# Input: root = [3,1,4,null,null,2]
# Output: [2,1,4,null,null,3]
# Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

# Constraints:
# The number of nodes in the tree is in the range [2, 1000].
# -231 <= Node.val <= 231 - 1
 
# Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        def inorder(node, prev, first, second):
            if not node:
                return

            # Traverse left subtree
            inorder(node.left, prev, first, second)

            # Check for swapped nodes
            if prev and node.val < prev.val:
                if not first:
                    first = prev
                second = node
            prev = node

            # Traverse right subtree
            inorder(node.right, prev, first, second)

        prev = None
        first, second = None, None
        inorder(root, prev, first, second)

        # Swap the values of the two nodes
        first.val, second.val = second.val, first.val


# Example usage
root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.right.left = TreeNode(2)

sol = Solution()
sol.recoverTree(root)

# Print the corrected BST (in-order traversal)


def print_inorder(node):
    if not node:
        return
    print_inorder(node.left)
    print(node.val, end=' ')
    print_inorder(node.right)


print_inorder(root)
