
// Problem Link == == >>https://leetcode.com/problems/course-schedule-ii/description/

//============> Solution - I(Topological Sort - BFS)

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> topologicalOrder;

        // Build the adjacency list and calculate indegrees
        for (const auto &pre : prerequisites)
        {
            adjList[pre[1]].push_back(pre[0]); // Representing edges as pre[1] -> pre[0]
            inDegree[pre[0]]++;
        }

        // Find all courses with no prerequisites (indegree 0)
        queue<int> zeroInDegreeCourses;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                zeroInDegreeCourses.push(i);
            }
        }

        // Topological sorting using BFS
        while (!zeroInDegreeCourses.empty())
        {
            int course = zeroInDegreeCourses.front();
            zeroInDegreeCourses.pop();
            topologicalOrder.push_back(course);

            for (int nextCourse : adjList[course])
            {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0)
                {
                    zeroInDegreeCourses.push(nextCourse);
                }
            }
        }

        // Check if a valid topological order exists
        if (topologicalOrder.size() == numCourses)
        {
            return topologicalOrder;
        }
        else
        {
            return {}; // Cycle detected
        }
    }
};

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    Solution solution;
    vector<int> order = solution.findOrder(numCourses, prerequisites);

    if (!order.empty())
    {
        cout << "Valid order: ";
        for (int course : order)
        {
            cout << course << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "There is a cycle in the prerequisites, no valid order exists." << endl;
    }

    return 0;
}

// =============>  Solution - II (Topological Sort - DFS)

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        vector<int> visited(numCourses, 0); // 0 - unvisited, 1 - exploring, 2 - visited
        vector<int> topologicalOrder;

        // Build the adjacency list
        for (const auto &pre : prerequisites)
        {
            adjList[pre[1]].push_back(pre[0]); // Representing edges as pre[1] -> pre[0]
        }

        if (!canFinish(adjList, visited, 0))
        {
            return {}; // Cycle detected
        }

        // Topological sorting using DFS recursion
        dfs(adjList, topologicalOrder, visited, 0);

        return topologicalOrder;
    }

private:
    bool canFinish(vector<vector<int>> &adjList, vector<int> &visited, int course)
    {
        if (visited[course] == 1)
        {
            return false; // Cycle detected
        }

        visited[course] = 1; // Mark as exploring

        for (int nextCourse : adjList[course])
        {
            if (visited[nextCourse] == 0 && !canFinish(adjList, visited, nextCourse))
            {
                return false; // Cycle detected through recursion
            }
        }

        visited[course] = 2; // Mark as visited
        return true;
    }

    void dfs(vector<vector<int>> &adjList, vector<int> &topologicalOrder, vector<int> &visited, int course)
    {
        visited[course] = 1; // Mark as exploring

        for (int nextCourse : adjList[course])
        {
            if (visited[nextCourse] == 0)
            {
                dfs(adjList, topologicalOrder, visited, nextCourse);
            }
        }

        visited[course] = 2;                // Mark as visited
        topologicalOrder.push_back(course); // Add course to order after exploring all its neighbors
    }
};

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    Solution solution;
    vector<int> order = solution.findOrder(numCourses, prerequisites);

    if (!order.empty())
    {
        cout << "Valid order: ";
        for (int course : order)
        {
            cout << course << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "There is a cycle in the prerequisites, no valid order exists." << endl;
    }

    return 0;
}
