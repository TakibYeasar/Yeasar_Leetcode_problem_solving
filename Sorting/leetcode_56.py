
# Problem link ===>>  https://leetcode.com/problems/merge-intervals/description/


class List:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        intervals.sort(key=lambda x: x[0])
        
        prev = intervals[0]
        
        for interval in intervals[1:]:
            if intervals[0] <= prev[1]:
                prev[1] = max(prev[1], interval[1])
            else:
                merged.append(prev)
                prev = interval
                
        merged.append(prev)
        return merged


if __name__ == "__main__":
    solution = Solution()
