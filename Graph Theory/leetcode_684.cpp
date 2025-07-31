
// Problem Link == == >>https://leetcode.com/problems/redundant-connection/description/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        unordered_set<int> cycle;
        int cycleStart = -1;

        // Build the graph from the edges
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Perform DFS to detect cycles and populate the cycle set
        dfs(graph, visited, cycle, cycleStart, 1);

        // Find the last edge in the input that has both nodes in the cycle
        for (int i = n - 1; i >= 0; --i)
        {
            if (cycle.count(edges[i][0]) && cycle.count(edges[i][1]))
            {
                return edges[i];
            }
        }

        return {}; // No redundant connection found
    }

private:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, unordered_set<int> &cycle, int &cycleStart, int cur, int par = -1)
    {
        if (visited[cur])
        {
            cycleStart = cur;
            return; // Found a cycle by reaching a visited node
        }

        visited[cur] = true;
        for (auto child : graph[cur])
        {
            if (child == par)
                continue; // Skip parent to avoid back-and-forth loop
            if (cycle.empty())
            {
                dfs(graph, visited, cycle, cycleStart, child, cur);
            }
            if (cycleStart != -1)
            {
                cycle.insert(cur); // Add current node to cycle set if cycle detected
            }
            if (cur == cycleStart)
            {
                cycleStart = -1;
                return; // Reached the start of the cycle, stop exploration
            }
        }
    }
};

int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    Solution s;
    vector<int> result = s.findRedundantConnection(edges);

    if (result.empty())
    {
        cout << "No redundant connection found." << endl;
    }
    else
    {
        cout << "Redundant connection: [" << result[0] << ", " << result[1] << "]" << endl;
    }

    return 0;
}
