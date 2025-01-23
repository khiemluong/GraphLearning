/*
If we are allowed to modify the original matrix, we can avoid an additional visited matrix. Whenever we visit a cell in matrix, we change its value to 0 so that it is not visited again

Time complexity: O(ROW x COL), where ROW is the number of rows and COL is the number of columns in the given matrix.
Auxiliary Space: O(ROW * COL), as to do DFS we need extra auxiliary stack space.
*/

// C++ Program to find the number of islands
// using Space Optimized DFS  

#include <bits/stdc++.h>
using namespace std;

// A utility function to perform DFS for a 2D
// boolean matrix. It only considers the 8 neighbors
// as adjacent vertices
void DFS(vector<vector<char>>& M, int r, int c) {
    int ROW = M.size();
    int COL = M[0].size();

    // Base condition
    // if r or c is out of bounds or M[r][c] is not 1
    if (r < 0 || c < 0 || r >= ROW || c >= COL || M[r][c] != '1') {
        return;
    }

    // Mark the cell as visited by setting it to 0
    M[r][c] = '0';

    // Traverse all 8 possible directions
    vector<int> rNbr = {1, -1, 0, 0, 1, -1, 1, -1};
    vector<int> cNbr = {0, 0, 1, -1, 1, -1, -1, 1};

    for (int i = 0; i < 8; ++i) {
        int newR = r + rNbr[i];
        int newC = c + cNbr[i];
        DFS(M, newR, newC);
    }
}

// function to count the number of islands
int countIslands(vector<vector<char>>& M) {
    int ROW = M.size();
    int COL = M[0].size();
    int count = 0;

    // Traverse the entire matrix
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++) {
          
            // If a cell with value 1 is found
            if (M[r][c] == '1') {
                  
                  // Increment the island count
                count++;
              
                // Start DFS from the current cell
                DFS(M, r, c);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> M = { { '1', '1', '0', '0', '0' },
                              { '0', '1', '0', '0', '1' },
                              { '1', '0', '0', '1', '1' },
                              { '0', '0', '0', '0', '0' },
                              { '1', '0', '1', '1', '0' } };

    cout << countIslands(M) << endl;
    return 0;
}