# Problem Link ====>>https://leetcode.com/problems/recover-binary-search-tree/description/

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
