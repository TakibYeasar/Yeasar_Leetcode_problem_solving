
# Problem Link ====>>https://leetcode.com/problems/container-with-most-water/description/

def maxArea(height):
    max_area = 0
    left = 0
    right = len(height) - 1

    while left < right:
        area = min(height[left], height[right]) * (right - left)
        max_area = max(max_area, area)

        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max_area


# Create a vector of integers for height
height = [1, 8, 6, 2, 5, 4, 7, 3, 1]

# Find the maximum area of the histogram
max_area = maxArea(height)

# Print the maximum area value
print("Maximum area of the histogram:", max_area)
