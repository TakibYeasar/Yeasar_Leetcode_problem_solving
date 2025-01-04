
# Problem link ===>>  https://leetcode.com/problems/powx-n/description/
# submission link == =>> https://leetcode.com/problems/powx-n/submissions/1497362495/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            x = 1/x
            n = -n
        
        pow_result = 1.0
        num = abs(n) 
        
        while num:
            if num & 1:  # If the least significant bit is set
                pow_result *= x
            x *= x  # Square the base
            num >>= 1  # Right shift num by 1 bit
            
        return pow_result
        
        


if __name__ == "__main__":
    solution = Solution()
