#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &img, int x, int y, int prevClr, int newClr)
{
    if (img[x][y] != prevClr)
        return;
    img[x][y] = newClr;
    int m = img[x].size();
    int n = img.size();
    if (x - 1 >= 0)
    {
        dfs(img, x - 1, y, prevClr, newClr);
    }
    if (x + 1 < m)
    {
        dfs(img, x + 1, y, prevClr, newClr);
    }
    if (y - 1 >= 0)
    {
        dfs(img, x, y - 1, prevClr, newClr);
    }
    if (y + 1 < n)
    {
        dfs(img, x, y + 1, prevClr, newClr);
    }
}

void floodFill(vector<vector<int>> &img, int x, int y, int newClr)
{
    if (img[x][y] == newClr)
        return;
    int prevClr = img[x][y];
    dfs(img, x, y, prevClr, newClr);
}

int main()
{
    vector<vector<int>> img = {{2, 1, 4},
                               {1, 1, 0},
                               {1, 0, 1}};
    int x = 1, y = 1;
    int newClr = 3;
    floodFill(img, x, y, newClr);
    for (const auto &row : img)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}