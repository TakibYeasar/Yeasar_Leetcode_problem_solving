
// Problem Link ====>>https://leetcode.com/problems/trapping-rain-water/description/

#include <bits/stdc++.h>
using namespace std;

int trapWater(vector<int> &height)
{
    int n = height.size();
    stack<int> st; // Stack to store indices of elevation bars
    int water = 0; // Total trapped water

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && height[i] > height[st.top()])
        {
            int bottom = st.top(); // Index of the bottom bar
            st.pop();

            if (st.empty())
            {
                break; // No left boundary, cannot trap water
            }

            int left = st.top();      // Index of the left boundary
            int width = i - left - 1; // Width of the trapped water
            int boundedHeight = min(height[left], height[i]) - height[bottom];
            water += width * boundedHeight;
        }

        st.push(i); // Push the current index onto the stack
    }

    return water;
}

int main()
{
    vector<int> elevationMap = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trappedWater = trapWater(elevationMap);
    cout << "Trapped water: " << trappedWater << " units" << endl;
    return 0;
}
