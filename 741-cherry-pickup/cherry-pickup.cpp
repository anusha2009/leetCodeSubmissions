class Solution {
public:
    int dp[50][50][50];
    vector<vector<int>> grid;
    int n;

    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        return max(0, dfs(0, 0, 0));
    }

    int dfs(int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;  // Total steps = r1 + c1 = r2 + c2

        // Boundary check
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (r1 == n - 1 && c1 == n - 1) return grid[r1][c1];  // Only need to check one person

        if (dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        int curr = grid[r1][c1];
        if (r1 != r2 || c1 != c2)  // Avoid double-counting same cell
            curr += grid[r2][c2];

        int best = max({
            dfs(r1 + 1, c1, r2 + 1),     // Down, Down
            dfs(r1, c1 + 1, r2),         // Right, Right
            dfs(r1 + 1, c1, r2),         // Down, Right
            dfs(r1, c1 + 1, r2 + 1)      // Right, Down
        });

        if (best == INT_MIN) return dp[r1][c1][r2] = INT_MIN;
        return dp[r1][c1][r2] = curr + best;
    }
};
