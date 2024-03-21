# Problem Link ====>>https://leetcode.com/problems/trapping-rain-water/description/

def trap_water(height):
    n = len(height)
    stack = []  # Stack to store indices of elevation bars
    water = 0   # Total trapped water

    for i in range(n):
        while stack and height[i] > height[stack[-1]]:
            bottom = stack.pop()  # Index of the bottom bar

            if not stack:
                break  # No left boundary, cannot trap water

            left = stack[-1]  # Index of the left boundary
            width = i - left - 1  # Width of the trapped water
            bounded_height = min(height[left], height[i]) - height[bottom]
            water += width * bounded_height

        stack.append(i)  # Push the current index onto the stack

    return water


# Example usage
elevation_map = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
trapped_water = trap_water(elevation_map)
print(f"Trapped water: {trapped_water} units")
