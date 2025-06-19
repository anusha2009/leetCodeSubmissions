#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<tuple<int, int, int>> q; // (row, col, minute)
        int fresh = 0, minutes = 0;

        // Step 1: Add all rotten oranges to the queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j, 0);
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // Step 2: BFS
        while (!q.empty()) {
            auto [x, y, minute] = q.front(); q.pop();
            minutes = max(minutes, minute);

            for (auto& d : directions) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    q.emplace(nx, ny, minute + 1);
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
