#include <bits/stdc++.h>

using namespace std;

bool isOK(vector<vector<int>> &mat, vector<vector<int>> &visited, int i, int j)
{
    if (i < 0)
        return false;
    if (i >= mat.size())
        return false;
    if (j < 0)
        return false;
    if (j >= mat[0].size())
        return false;
    if (mat[i][j] != 1)
        return false;
    if (visited[i][j] != 0)
        return false;
    return true;
}

void backTracking(vector<vector<int>> &mat, vector<vector<int>> &visited, int x, int y, int i, int j, int &min_dist, int dist)
{
    if (x == i && y == j)
    {
        min_dist = min(dist, min_dist);
        cout << "OK: " << min_dist << endl;
        return;
    }
    visited[i][j] = 1;
    if (isOK(mat, visited, i - 1, j))
    {
        cout << "go up: " << dist << endl;
        backTracking(mat, visited, x, y, i - 1, j, min_dist, dist + 1);
    }
    if (isOK(mat, visited, i + 1, j))
    {
        cout << "go down: " << dist << endl;
        backTracking(mat, visited, x, y, i + 1, j, min_dist, dist + 1);
    }
    if (isOK(mat, visited, i, j - 1))
    {
        cout << "go left: " << dist << endl;
        backTracking(mat, visited, x, y, i, j - 1, min_dist, dist + 1);
    }
    if (isOK(mat, visited, i, j + 1))
    {
        cout << "go right: " << dist << endl;
        backTracking(mat, visited, x, y, i, j + 1, min_dist, dist + 1);
    }
    visited[i][j] = 0;
}

int findShortestPathLength(vector<vector<int>> &mat, pair<int, int> src, pair<int, int> dest)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> visited = vector<vector<int>>(row, vector<int>(col, 0));

    int x = src.first;
    int y = src.second;
    int i = dest.first;
    int j = dest.second;

    int min_dist = INT_MAX;

    backTracking(mat, visited, x, y, i, j, min_dist, 0);
    return min_dist;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
                               {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
                               {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                               {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                               {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                               {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
                               {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                               {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                               {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}};

    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(3, 4);

    int dist = findShortestPathLength(mat, src, dest);
    if (dist != INT_MAX)
    {
        cout << "Shortest Path is: " << dist << endl;
    }
    else
    {
        cout << "Shortest Path doesnt exist!" << endl;
    }
    return 0;
}