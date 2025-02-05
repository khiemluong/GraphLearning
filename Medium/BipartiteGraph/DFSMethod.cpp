#include <bits/stdc++.h>
using namespace std;

// Helper function for DFS to check bipartite graph
bool dfs(int u, int color, vector<int> &colors,
         vector<vector<int>> &adj)
{

    // Assign color to the current u
    colors[u] = color;

    // Iterate through all adjacent vertices
    for (auto &v : adj[u])
    {
        if (colors[v] == -1)
        {

            // Assign alternate color to the adjacent u
            if (!dfs(v, 1 - color, colors, adj))
                return false;
        }
        else if (colors[v] == color)
        {

            // If the adjacent u has the same color,
            // it's not bipartite
            return false;
        }
    }
    return true;
}

// Function to check if the graph is Bipartite using DFS
bool isBipartite(int V, vector<vector<int>> &adj)
{

    // Initialize all vertices as uncolored
    vector<int> colors(V, -1);

    // Check each component of the graph
    for (int i = 0; i < V; i++)
    {

        // If the vertex is uncolored
        if (colors[i] == -1)
        {

            // If DFS fails, the graph is not bipartite
            if (!dfs(i, 0, colors, adj))
                return false;
        }
    }

    // All vertices can be colored bipartitely
    return true;
}

int main()
{
    // Graph Structure:
    // 0 - 1
    // |   |
    // 3 - 2
    int V = 4;
    vector<vector<int>> adj(V);

    // Adding edges (undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);

    if (isBipartite(V, adj))
        cout << "true";
    else
        cout << "false";

    return 0;
}