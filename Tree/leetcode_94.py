# Problem Link ====>>https://leetcode.com/problems/binary-tree-inorder-traversal/description/

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        

class Solution(object):
    def inorderTraversal(self, root):
        def helper(root, result):
          if root != None:
            helper(root.left, result)
            result.append(root.val)
            helper(root.right, result)

        result = []
        helper(root, result)
        return result


# Create a sample tree
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)

# Create an instance of the Solution class
solution = Solution()

# Call the inorderTraversal function to get the inorder traversal sequence
result = solution.inorderTraversal(root)

# Print the inorder traversal sequence
print("Inorder traversal:", result)
