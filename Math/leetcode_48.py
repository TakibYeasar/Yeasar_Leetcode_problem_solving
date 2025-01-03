
# Problem link ===>>  https://leetcode.com/problems/rotate-image/description/
# submission link == =>> https://leetcode.com/problems/rotate-image/submissions/1496330563/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        
        # Transpose the matrix
        for i in range(n):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # Reverse each row
        for row in matrix:
            row.reverse()


if __name__ == "__main__":
    solution = Solution()
