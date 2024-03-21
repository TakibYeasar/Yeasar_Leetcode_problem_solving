
// Problem Link == == >>https://leetcode.com/problems/course-schedule/description/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Check if the number of courses is valid
        if (numCourses <= 0)
        {
            return false;
        }

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        // Build the adjacency list and calculate indegrees
        for (auto &edge : prerequisites)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        // Find courses with no prerequisites (indegree 0)
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Topological sorting using BFS
        int completed = 0;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            completed++;

            // Decrement indegrees of neighbors
            for (int neighbor : adj[course])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // Check if all courses were completed (no cycles)
        return completed == numCourses;
    }
};

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}}; // Example dependency: course 1 needs to be completed before course 0

    Solution solution;
    bool can_finish = solution.canFinish(numCourses, prerequisites);

    if (can_finish)
    {
        cout << "The courses can be completed in a valid order." << endl;
    }
    else
    {
        cout << "There is a cycle in the prerequisites and the courses cannot be completed." << endl;
    }

    return 0;
}
