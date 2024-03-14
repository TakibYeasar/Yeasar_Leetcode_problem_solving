
// Given a reference of a node in a connected undirected graph.
// Return a deep copy (clone) of the graph.
// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }


// Test case format:
// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node 
// with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

// An adjacency list is a collection of unordered lists used to represent a finite graph. 
// Each list describes the set of neighbors of a node in the graph.

// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

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