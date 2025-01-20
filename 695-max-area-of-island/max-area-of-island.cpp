class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int max_area = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) { // Check for land cells (`1`)
                    int area = 0;
                    dfs(i, j, grid, visited, area); // DFS computes the area
                    max_area = max(max_area, area); // Track the largest area
                }
            }
        }

        return max_area; // Return the maximum island area
    }

private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col]) {
            return; // Stop if out of bounds, water cell, or already visited
        }

        visited[row][col] = true;
        area++; // Increment the area for each valid land cell

        // Explore all 4 directions (up, down, left, right)
        dfs(row, col + 1, grid, visited, area); // Right
        dfs(row, col - 1, grid, visited, area); // Left
        dfs(row - 1, col, grid, visited, area); // Up
        dfs(row + 1, col, grid, visited, area); // Down
    }
};