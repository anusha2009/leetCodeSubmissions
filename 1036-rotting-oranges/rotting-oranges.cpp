class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // If the grid is empty or its rows are empty, return -1 as an error.
        if (grid.empty() || grid[0].empty()) return -1;

        int m = grid.size();         // Number of rows.
        int n = grid[0].size();      // Number of columns.
        int total = 0;               // Total count of non-empty cells (fresh + rotten oranges).
        int count = 0;               // Count of visited cells (rotten oranges processed).
        
        // Distance matrix to keep track of the minimum time to rot each cell.
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // Queue for BFS, storing the (row, col, time) of each cell.
        queue<tuple<int, int, int>> q;

        // Directions array to simplify moving up, down, left, and right.
        vector<pair<int, int>> dirc = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // Initialize the grid and BFS queue with the initial rotten oranges.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) { // Rotten orange found.
                    q.push({i, j, 0}); // Push its position and time (0) to the queue.
                    dist[i][j] = 0;    // Distance to itself is 0.
                    count++;           // Increment the count of processed cells.
                }
                if (grid[i][j]) total++; // Count non-empty cells.
            }
        }

        int ans = 0; // Tracks the maximum time needed to rot all oranges.

        // Perform BFS to rot fresh oranges.
        while (!q.empty()) {
            auto [x, y, z] = q.front(); // Dequeue the next cell (x, y) with its time z.
            q.pop();

            // Visit all 4 adjacent cells.
            for (auto [i, j] : dirc) {
                int new_r = x + i;     // Compute new row index.
                int new_c = y + j;     // Compute new column index.

                // Check if the new cell is valid and has a fresh orange.
                if (new_r >= 0 && new_c >= 0 && new_r < m && new_c < n && grid[new_r][new_c] == 1) {
                    // If this path reaches the fresh orange faster than any previous path.
                    if (dist[new_r][new_c] >= z + 1) {
                        grid[new_r][new_c] = 2;     // Rot the fresh orange.
                        dist[new_r][new_c] = z + 1; // Update the minimum time to rot this cell.
                        ans = max(ans, z + 1);     // Update the maximum time.
                        q.push({new_r, new_c, z + 1}); // Push the cell into the queue.
                        count++;                   // Increment the count of processed cells.
                    }
                }
            }
        }

        // If we processed all non-empty cells, return the max time; otherwise, return -1.
        return (count == total) ? ans : -1;
    }
};
