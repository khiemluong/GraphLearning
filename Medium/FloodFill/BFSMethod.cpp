#include <bits/stdc++.h>
using namespace std;

// Fill the image img[x][y] and all its same colored
// adjacent with the given new color
void floodFill(vector<vector<int>> &img, int x,
               int y, int newClr)
{

    queue<pair<int, int>> q;

    // Rows and columns of the display
    int m = img.size();
    int n = img[0].size();

    int prevClr = img[x][y];
    if (prevClr == newClr)
        return;

    // Append the position of starting pixel
    // of the component
    q.push({x, y});
    img[x][y] = newClr;

    // While the queue is not empty i.e. the
    // whole component having prevClr color
    // is not colored with newClr color
    while (!q.empty())
    {

        // Dequeue the front node
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // Check if the adjacent pixels are valid
        // and enqueue
        if (x + 1 < m && img[x + 1][y] == prevClr)
        {
            img[x + 1][y] = newClr;
            q.push({x + 1, y});
        }
        if (x - 1 >= 0 && img[x - 1][y] == prevClr)
        {
            img[x - 1][y] = newClr;
            q.push({x - 1, y});
        }
        if (y + 1 < n && img[x][y + 1] == prevClr)
        {
            img[x][y + 1] = newClr;
            q.push({x, y + 1});
        }
        if (y - 1 >= 0 && img[x][y - 1] == prevClr)
        {
            img[x][y - 1] = newClr;
            q.push({x, y - 1});
        }
    }
}

int main()
{
    vector<vector<int>> img = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int x = 1, y = 1;
    int newClr = 3;

    floodFill(img, x, y, newClr);

    // Printing the updated img
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