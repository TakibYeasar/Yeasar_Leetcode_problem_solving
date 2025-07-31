// Problem Link == == >> https://leetcode.com/problems/clone-graph/description/

#include<bits/stdc++.h>
                              using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        unordered_map<Node *, Node *> visited;
        return dfs(node, visited);
    }

private:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &visited)
    {
        if (visited.count(node))
        {
            return visited[node];
        }

        Node *clone = new Node(node->val);
        visited[node] = clone;

        for (Node *neighbor : node->neighbors)
        {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }

        return clone;
    }
};

int main()
{
    // Create a sample graph
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node1);
    node3->neighbors.push_back(node2);

    // Clone the graph
    Solution solution;
    Node *clonedGraph = solution.cloneGraph(node1);

    // You can now use the cloned graph here

    return 0;
}
