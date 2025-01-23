/*
Naive Approach:  
Traverse through all oranges in multiple rounds. In every round, rot the oranges to the adjacent position of oranges 
that were rotten in the last round. For the first round we consider all initially rotten oranges.


Time Complexity: O((R*C) * (R *C)), 

The matrix needs to be traversed again and again until there is no change in the matrix, that can happen max(R *C)/2 times. 
So time complexity is O((R * C) * (R *C)).
Auxiliary Space: O(1), No extra space is required.
*/


#include <iostream>
#include <vector>
using namespace std;

// Check if i, j is within the array limits
// of row and column
bool isSafe(int i, int j, int rows, int cols) {
    return (i >= 0 && i < rows && j >= 0 && j < cols);
}

int rotOranges(vector<vector<int>>& v) {
    int rows = v.size();
    int cols = v[0].size();
    bool changed = false;
    int no = 2;

    while (true) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
              
                // Rot all other oranges present at
                // (i+1, j), (i, j-1), (i, j+1), (i-1, j)
                if (v[i][j] == no) {
                    if (isSafe(i + 1, j, rows, cols) && v[i + 1][j] == 1) {
                        v[i + 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (isSafe(i, j + 1, rows, cols) && v[i][j + 1] == 1) {
                        v[i][j + 1] = v[i][j] + 1;
                        changed = true;
                    }
                    if (isSafe(i - 1, j, rows, cols) && v[i - 1][j] == 1) {
                        v[i - 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (isSafe(i, j - 1, rows, cols) && v[i][j - 1] == 1) {
                        v[i][j - 1] = v[i][j] + 1;
                        changed = true;
                    }
                }
            }
        }

        // if no oranges were rotten in
        // this round, break the loop
        if (!changed) break;
        changed = false;
        no++;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          
            // if any orange is found to 
            // be not rotten, return -1
            if (v[i][j] == 1) return -1;
        }
    }

    // Because initial value for
    // a rotten orange was 2
    return no - 2;
}

// Driver function
int main() {
    vector<vector<int>> v = { { 2, 1, 0, 2, 1 },
                              { 1, 0, 1, 2, 1 },
                              { 1, 0, 0, 2, 1 } };

    cout << "Max time incurred: " 
         << rotOranges(v) << endl;

    return 0;
}