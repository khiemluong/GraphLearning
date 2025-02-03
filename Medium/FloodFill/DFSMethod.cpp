#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &img, int x, int y,
         int prevClr, int newClr)
{

    if (img[x][y] != prevClr)
        return;

    // Marking it as the new color
    img[x][y] = newClr;

    // Moving up, right, down and left one
    // by one.
    int n = img.size();
    int m = img[0].size();
    if (x - 1 >= 0l)
        dfs(img, x - 1, y, prevClr, newClr);
    if (y + 1 < m)
        dfs(img, x, y + 1, prevClr, newClr);
    if (x + 1 < n)
        dfs(img, x + 1, y, prevClr, newClr);
    if (y - 1 >= 0)
        dfs(img, x, y - 1, prevClr, newClr);
}

// FloodFill Function
void floodFill(vector<vector<int>> &img,
               int x, int y, int newClr)
{

    int prevClr = img[x][y];
    if (prevClr == newClr)
        return;
    dfs(img, x, y, prevClr, newClr);
}

// Driver code
int main()
{
    vector<vector<int>> img = {{1, 1, 1},
                               {1, 1, 0},
                               {1, 0, 1}};
    // Co-ordinate provided by the user
    int x = 1;
    int y = 1;

    // New color that has to be filled
    int newClr = 3;
    floodFill(img, x, y, newClr);

    // Printing the updated img
    for (int i = 0; i < img.size(); i++)
    {
        for (int j = 0; j < img[0].size(); j++)
        {
            cout << img[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}