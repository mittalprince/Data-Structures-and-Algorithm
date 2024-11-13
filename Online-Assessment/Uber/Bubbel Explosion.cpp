/*
Imagine you are given a board of cells, each
HISTORY
containing a bubble of a specific color (as shown below). Neighboring cells of the bubble are defined as adjacent cells (on either the same row or column as the given cell) which have a common side with the given cell. For
RULES
example, tie neighboring cells for each of the cells A, B, and c are highlighted in corresponding color in the picture below.

Your task is to perform a bubble explosion on the board. A bubble explosion is defined by the following rules:
• A bubble within any given cell is eligible to explode if it has the same color as bubbles in at least 2 neighboring cells.
• All eligible bubbles and bubbles of the same color in neighboring cells are marked for explosion.
• All marked bubbles explode at the same time. Exploded bubbles are removed from the board, resulting in empty cells.
• After all exploded bubbles are removed, remaining bubbles in cells above the empty cells drop down to fill all empty cells.

You are given an initial board of cells bubbles
- a multidimensional array of integers representing cells containing bubbles of various colors. Return the board state after a bubble explosion. The output should be a multidimenaional array of integers with the same size as bubbles, but replacing all empty cells (without bubbles) with 0.
Note: You are not expected to provide the most optimal solution, but a solution with time complexity not worse than o (bubbles. length?
• bubbles (0]. length?) will fit within the execution time limit.

Example
For
bubbles = [ [3, 1, 2, 11,
[1, 1, 1, 41,
[3, 1, 2, 21,
[3, 3, 3, 41]
the output should be
solution (bubbles) = 
[[O, 0, 0, 1],
10, 0, 0, 41,
10, 0, 2, 2]r
[3, 0, 2, 4]]
*/

#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> bubbleExplosion(vector<vector<int>>& bubbles) {
    int rows = bubbles.size();
    int cols = bubbles[0].size();

    // Directions for neighbors (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (true) {
        bool exploded = false;
        vector<vector<bool>> toExplode(rows, vector<bool>(cols, false));

        // Step 1: Identify bubbles to explode
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (bubbles[i][j] == 0) continue;

                int color = bubbles[i][j];
                int sameColorCount = 0;

                for (auto& dir : directions) {
                    int ni = i + dir.first, nj = j + dir.second;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && bubbles[ni][nj] == color) {
                        ++sameColorCount;
                    }
                }

                if (sameColorCount >= 2) {
                    toExplode[i][j] = true;
                    exploded = true;

                    // Mark neighboring cells of the same color for explosion
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for (auto& dir : directions) {
                            int nx = x + dir.first, ny = y + dir.second;
                            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && bubbles[nx][ny] == color && !toExplode[nx][ny]) {
                                toExplode[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        // If no bubbles are marked for explosion, stop the loop
        if (!exploded) break;

        // Step 2: Explode bubbles
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (toExplode[i][j]) {
                    bubbles[i][j] = 0;
                }
            }
        }

        // Step 3: Apply gravity to drop bubbles down
        for (int j = 0; j < cols; ++j) {
            int writeRow = rows - 1;
            for (int i = rows - 1; i >= 0; --i) {
                if (bubbles[i][j] != 0) {
                    bubbles[writeRow--][j] = bubbles[i][j];
                }
            }
            while (writeRow >= 0) {
                bubbles[writeRow--][j] = 0;
            }
        }
    }

    return bubbles;
}
