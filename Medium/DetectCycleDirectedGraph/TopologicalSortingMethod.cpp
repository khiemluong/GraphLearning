#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to add an edge to the adjacency list
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

// Function to detect cycle in a directed graph
bool isCyclic(vector<vector<int>>& adj) {
    
    int V = adj.size();
  
    // stores in-degree of each vertex
    vector<int> inDegree(V, 0); 
  
    // queue to store vertices with 0 in-degree
    queue<int> q; 
  
    int visited = 0; // count of visited vertices

    // Calculate in-degree of each vertex
    for (int u = 0; u < V; u++) {
        for (auto v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Enqueue vertices with 0 in-degree
    for (int u = 0; u < V; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    // BFS traversal
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited++;

        // Reduce in-degree of adjacent vertices
        for (auto v : adj[u]) {
            inDegree[v]--;
          
            // If in-degree becomes 0, enqueue it
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If not all vertices are visited, cycle
    return visited != V; 
}

// Driver function
int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    // Function call to check for cycles
    if (isCyclic(adj)) {
        cout << "Contains cycle" << endl;
    } else {
        cout << "No Cycle" << endl;
    }

    return 0;
}
