
// Problem Link == == >>https://leetcode.com/problems/redundant-connection-ii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1, -1);
        vector<int> in(n + 1, -1);
        int e1 = -1, e2 = -1;

        for (int i = 0; i < n; i++)
        {
            if (in[edges[i][1]] != -1)
            {                         // indegree 2
                e2 = in[edges[i][1]]; // first edge causing indegree 2
                e1 = i;               // second edge causing indegree 2
                break;
            }
            in[edges[i][1]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (i == e1)
                continue; // ignore edge causing indegree 2

            if (!union_by_weight(edges[i][0], edges[i][1], parent))
            { // cycle is present
                if (e1 != -1)
                    return edges[e2]; // indegree 2, wrong edge ignored
                else
                    return edges[i]; // indegree 1, remove edge causing cycle
            }
        }

        return e1 != -1 ? edges[e1] : vector<int>(); // return empty vector if no indegree 2
    }

private:
    int find(int u, vector<int> &parent)
    {
        if (parent[u] < 0)
            return u;
        parent[u] = find(parent[u], parent);
        return parent[u];
    }

    bool union_by_weight(int u, int v, vector<int> &parent)
    {
        int pu = find(u, parent);
        int pv = find(v, parent);

        if (pu == pv)
            return false; // cycle detected

        if (parent[pu] < parent[pv])
        {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else
        {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    Solution s;
    vector<int> result = s.findRedundantDirectedConnection(edges);

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
