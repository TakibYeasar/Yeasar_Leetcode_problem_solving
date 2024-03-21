
# Problem Link ====>>https://leetcode.com/problems/trapping-rain-water/description/

def trap(height):
    left, right = 0, len(height) - 1
    left_max, right_max = 0, 0
    trapped_water = 0

    while left < right:
        # Update the maximum heights from left and right
        left_max = max(left_max, height[left])
        right_max = max(right_max, height[right])

        # Calculate trapped water for the current position
        if left_max < right_max:
            trapped_water += left_max - height[left]
            left += 1
        else:
            trapped_water += right_max - height[right]
            right -= 1

    return trapped_water


# Example usage
elevation_map = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
trapped_water = trap(elevation_map)
print(f"Trapped water: {trapped_water} units")
