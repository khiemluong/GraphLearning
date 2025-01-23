// C++ Program to Implement a Graph Using Adjacency List
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    vector<vector<int>> adjList; // Adjacency list to store the graph

public:
    // Constructor to initialize the graph with 'n' vertices
    Graph(int n)
    {
        adjList = vector<vector<int>>(n, vector<int>(n, 0));
    }
    // Function to add an edge between vertices u and v of
    // the graph
    void add_edge(int u, int v)
    {
        // Add edge from u to v
        adjList[u].push_back(v);
        // Add edge from v to u because the graph is
        // undirected
        adjList[v].push_back(u);
    }

    void BFS(int s)
    {
        // Create a queue for BFS
        queue<int> q;

        // Initially mark all the vertices as not visited
        // When we push a vertex into the q, we mark it as
        // visited
        vector<bool> visited(adjList.size(), false);

        // Mark the source node as visited and
        // enqueue it
        visited[s] = true;
        q.push(s);

        // Iterate over the queue
        while (!q.empty())
        {

            // Dequeue a vertex from queue and print it
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            // Get all adjacent vertices of the dequeued
            // vertex curr If an adjacent has not been
            // visited, mark it visited and enqueue it
            for (int x : adjList[curr])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }
};

int main()
{
    int V = 5;
    // Create a graph object
    Graph g(V);

    // Add edges to create the graph
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);

    // Perform BFS traversal starting from vertex 0
    cout << "BFS starting from 0 : \n";
    g.BFS(0);

    return 0;
}