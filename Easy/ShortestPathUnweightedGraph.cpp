#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    vector<vector<int>> adj_list;

public:
    Graph(int n)
    {
        adj_list = vector<vector<int>>(n);
    }

    void add_edges(int u, int v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    void BFS(int s, vector<int> &par, vector<int> &dist)
    {
        queue<int> q;

        dist[s] = 0;
        q.push(s);

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (auto neighbor : adj_list[cur])
            {
                if (dist[neighbor] == 1e9)
                {
                    par[neighbor] = cur;
                    dist[neighbor] = dist[cur] + 1;
                    q.push(neighbor);
                }
            }
        }
    }

    void print_shortest_distance(int s, int d)
    {
        vector<int> par(adj_list.size(), -1);
        vector<int> dist(adj_list.size(), 1e9);

        BFS(s, par, dist);

        if (dist[d] == 1e9)
        {
            cout << "Source and Destination are not connected!";
            return;
        }

        vector<int> path;
        int cur = d;
        path.push_back(d);
        while (par[cur] != -1)
        {
            path.push_back(par[cur]);
            cur = par[cur];
        }

        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
    }
};

int main()
{
    int v = 8;
    Graph g(v);
    int s = 2, d = 6;

    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 3}, {3, 4}, {4, 7}, {3, 7}, {6, 7}, {4, 5}, {4, 6}, {5, 6}};
    for (auto edge : edges)
    {
        g.add_edges(edge[0], edge[1]);
    }

    g.print_shortest_distance(s, d);

    return 0;
}