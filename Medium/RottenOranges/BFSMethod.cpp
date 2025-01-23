/*
Using Breadth First Search:
The idea is to use Breadth First Search. In the previous approach, the idea was based on BFS but the implementation was poor and inefficient. Here we use queue data structure.


Follow the steps below to solve the problem:

- Create an empty queue Q. 
- Find all rotten oranges and enqueue them to Q. Also, enqueue a delimiter to indicate the beginning of the next time frame.
- Run a loop While Q is not empty and do the following while the delimiter in Q is not reached
    + Dequeue an orange from the queue, and rot all adjacent oranges. 
    + While rotting the adjacent, make sure that the time frame is incremented only once. And the time frame is not incremented if there are no adjacent oranges.
    + Dequeue the old delimiter and enqueue a new delimiter. The oranges rotten in the previous time frame lie between the two delimiters.
- Return the last time frame.

Time Complexity: O( R *C), Each element of the matrix can be inserted into the queue only once so the upper bound of iteration is O(R*C)
Auxiliary Space: O(R*C), To store the elements in a queue.
*/

// C++ program to find minimum time required to make all
// oranges rotten
#include <bits/stdc++.h>
using namespace std;

// This function first finds if it is possible to rot 
// all oranges or not. If possible, then it returns 
// minimum time required to rot all, otherwise returns -1
int rotOranges(vector<vector<int> >& grid)
{
    int n = grid.size(); 
    int m = grid[0].size(); 

    // delrow and delcol are used to traverse in
    // up,right,bottom and left respectively.
    int delrow[] = { -1, 0, 1, 0 };
    int delcol[] = { 0, 1, 0, -1 };

    // visited matrix to keep track of the visited cell.
    int vis[n][m];

    // queue stores rowIndex,colIndex and time taken to rot
    // respectively.
    queue<pair<pair<int, int>, int> > q;

    // counter to keep track of fresh cells.
    int cntfresh = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          
            // already rotten hence 0 time to rot.
            // and mark as visited
            if (grid[i][j] == 2) {
                q.push({ { i, j }, 0});
                vis[i][j] = 2; 
            }
            else {
                vis[i][j] = 0; // unvisited
            }
          
            // Increment count for fresh oranges.
            if (grid[i][j] == 1)
                cntfresh++; 
        }
    }
    int cnt = 0, tm = 0;
    while (!q.empty()) {
      
        int row = q.front().first.first; 
        int col = q.front().first.second; 
        int t = q.front().second; 
      
        q.pop();

        tm = max(tm, t);

        // checking for adjacent nodes in 4 directions.
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // checking the validity of a node and also
            // vis[nrow][ncol] !=2
            if (nrow >= 0 && nrow < n && ncol >= 0
                && ncol < m && grid[nrow][ncol] == 1
                && vis[nrow][ncol] != 2) {
              
                // adj orange is rotten
                vis[nrow][ncol] = 2;
              
                // incrementing time for that orange by 1
                q.push({ { nrow, ncol }, t + 1 }); 
                cnt++;
            }
        }
    }

    return (cnt == cntfresh) ? tm : -1;
}

// Driver program
int main()
{
    vector<vector<int> > arr = { { 2, 1, 0, 2, 1 },
                                 { 1, 0, 1, 2, 1 },
                                 { 1, 0, 0, 2, 1 } };
    int ans = rotOranges(arr);
    if (ans == -1)
        cout << "All oranges cannot rotn";
    else
        cout << "Time required for all oranges to rot : "
             << ans << endl;
    return 0;
}