/*
Depth First Traversal can be used to detect a cycle in an undirected Graph. If we encounter a visited vertex again, then we say, there is a cycle. 
But there is a catch in this algorithm, we need to make sure that we do not consider every edge as a cycle because in an undirected graph, an edge 
from 1 to 2 also means an edge from 2 to 1. To handle this, we keep track of the parent node (the node from which we came to the current node) 
in the DFS traversal and ignore the parent node from the visited condition. 

Follow the below steps to implement the above approach:

- Iterate over all the nodes of the graph and Keep a visited array visited[] to track the visited nodes.
- If the current node is not visited, run a Depth First Traversal on the given subgraph connected to the current node and pass the parent of the current node as -1. Recursively, perform the following steps:
    + Set visited[root] as 1.
    + Iterate over all adjacent nodes of the current node in the adjacency list 
        If it is not visited then run DFS on that node and return true if it returns true.
        Else if the adjacent node is visited and not the parent of the current node then return true.
    + Return false.

O(V+E) time and O(V) space
*/

// A C++ Program to detect
// cycle in an undirected graph
#include <iostream>
#include <vector>
using namespace std;

// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool isCycleUtil(int v, vector<vector<int>>& adj, 
    vector<bool>& visited, int parent) {
                      
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    for (int i : adj[v]) {
        
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[i]) {
            if (isCycleUtil(i, adj, visited, v))
                return true;
        }
        
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (i != parent)
            return true;
    }
    
    return false;
}

// Returns true if the graph contains
// a cycle, else false.
bool isCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Call the recursive helper function
    // to detect cycle in different DFS trees
    for (int u = 0; u < V; u++) {
        
        // Don't recur for u if 
        // it is already visited
        if (!visited[u])
            if (isCycleUtil(u, adj, visited, -1))
                return true;
    }
    
    return false;
}

int main() {
    int V = 3;
    vector<vector<int>> adj(V);

    adj[1].push_back(0);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);

    if (isCycle(adj)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
