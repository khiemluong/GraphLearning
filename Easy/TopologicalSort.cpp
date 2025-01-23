#include <bits/stdc++.h>
using namespace std;

// perform DFS and topological sorting
void topologicalSortUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s)
{
    // mark the current node as visited
    visited[v] = true;

    // Recursive for all adjacent vertices
    for (auto i : adj[v]) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, s);
        }
    }

    // push current vertex to stack which stores the result
    s.push(v);
}

// perform topological sort
void topologicalSort(vector<vector<int>> &adj, int v)
{
    // init stack to store the result, visited array
    stack<int> s;
    vector<bool> visited(v, false);

    // call topologicalSortUtil from all vertices
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, s);
        }
    }

    // print stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    // Number of nodes
    int V = 4;

    // Edges
    vector<vector<int> > edges
        = { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };

    // Graph represented as an adjacency list
    vector<vector<int> > adj(V);

    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }

    cout << "Topological sorting of the graph: ";
    topologicalSort(adj, V);

    return 0;
}