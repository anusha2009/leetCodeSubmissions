class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> vis;
        vis = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for(int i = 0; i<grid.size(); i++) {
            for(int j = 0; j<grid[0].size(); j++) {
                if(grid[i][j] == 0 && i != 0 && i != grid.size()-1 && j != 0 && j != grid[0].size()-1 && !vis[i][j]) {
                    if(dfs(i, j, grid, directions, vis)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    bool dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& directions, vector<vector<bool>>& vis) {
        if(grid[row][col] == 1) {
            return true;
        }
        if((row == 0 || row == grid.size()-1 || col == 0 || col == grid[0].size()-1) && grid[row][col] == 0) {
            return false;
        }
        vis[row][col] = true;
        bool ans = true;
        for(auto dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol <grid[0].size() && !vis[newRow][newCol]) {
                if(!dfs(newRow, newCol, grid, directions, vis)) {
                    ans = false;
                }
            }
        }
        return ans;
    }
};