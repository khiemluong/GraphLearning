// C++ Program to Implement a Graph Using Adjacency List
#include <iostream>
#include <list>
#include <map>
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

    void DFSRec(vector<bool> &visited, int s)
    {
        visited[s] = true;

        // Print the current vertex
        cout << s << " ";

        // Recursively visit all adjacent vertices
        // that are not visited yet
        for (int i : adjList[s])
            if (visited[i] == false)
                DFSRec(visited, i);
    }

    void DFS(int s)
    {
        vector<bool> visited(adjList.size(), false);
        DFSRec(visited, s);
    }
};

int main()
{
    int V = 5;
    // Create a graph object
    Graph g(V);

    // Add edges
    vector<vector<int>> edges={{1, 2},{1, 0},{2, 0},{2, 3},{2, 4}};
    for (auto &e : edges)
        g.add_edge(e[0], e[1]);

    int s = 1; // Starting vertex for DFS
    cout << "DFS from source: " << s << endl;
    g.DFS(s); // Perform DFS starting from the source vertex

    return 0;
}