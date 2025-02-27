/*
The idea is to use BFS to detect a cycle in an undirected graph. We start BFS for all components of the graph and check if a node has been visited earlier, 
ensuring that we do not consider the parent node of the current node while making this check. If we encounter a visited node that is not the parent, a cycle 
exists in the graph. Otherwise, we continue BFS by marking the node as visited and inserting it into the queue.

Step by step approach:

- Initialize a visited array of size n (number of nodes) to false.
- Iterate through all nodes from 0 to n-1. If a node is not visited, start BFS.
- Push the node into the queue with its parent set to -1.
- Perform BFS:
    + Pop a node from the queue.
    + Traverse all its adjacent nodes.
    + If an adjacent node is visited and is not the parent, return true (cycle detected).
    + Otherwise, if the adjacent node is not visited, mark it as visited and push it into the queue with the current node as its parent.
- If no cycle is found after checking all components, return false.

Time Complexity: The program does a simple BFS Traversal of the graph and the graph is represented using an adjacency list. So the time complexity is O(V+E)
Space Complexity: O(V) for BFS queue and visited array.
*/

// C++ program to Detect cycle in 
// an undirected graph using BFS
#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS from node start
bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            
            // If node is not visited,
            // push it into queue.
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } 
            
            // If node is visited and 
            // it is not the parent node.
            else if (neighbor != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        
        // If node is not visited,
        // start BFS from this node.
        if (!visited[i]) {
            
            // If cycle is found in this 
            // component.
            if (bfs(i, adj, visited)) {
                return true;
            }
        }
    }
    
    // If no cycle is found
    return false;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2, 3},
        {0, 2},
        {0, 1},
        {0, 4},
        {3}
    };

   isCycle(adj) ? cout<<"True": cout<<"False";

    return 0;
}
