# Problem Link ====>>https://leetcode.com/problems/validate-binary-search-tree/description/

class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def inorder(node, prev: int) ->bool:
            if not node:
                return True
            
            if not inorder(node.left, prev):
                return False
            
            if prev is not None and prev >=node.val:
                return False
            
            prev = node.val
            return inorder(node.right, prev)
        return inorder(root, None)


if __name__ == "__main__":
    # Test case examples
    root1 = TreeNode(5, TreeNode(1), TreeNode(4))
    root2 = TreeNode(5, TreeNode(1), TreeNode(6))
    root3 = TreeNode(2, TreeNode(1), TreeNode(3))
    solution = Solution()

    print(f"Is root1 a valid BST: {solution.isValidBST(root1)}")
    print(f"Is root2 a valid BST: {solution.isValidBST(root2)}")
    print(f"Is root3 a valid BST: {solution.isValidBST(root3)}")
