class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> memo;
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        this->grid = grid;
        memo = vector(m, vector(n, -1));
        return dp(m - 1, n - 1);
    }
    
    int dp(int row, int col) {
        if (row + col == 0) {
            return grid[row][col]; // Base case
        }
        
        if (memo[row][col] != - 1) {
            return memo[row][col];
        }
        
        int ans = INT_MAX;
        if (row > 0) {
            ans = min(ans, dp(row - 1, col));
        }
        if (col > 0) {
            ans = min(ans, dp(row, col - 1));
        }
        
        memo[row][col] = grid[row][col] + ans;
        return memo[row][col];
    }
};

//bottom-up

/*

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector(n, 0));
        dp[0][0] = grid[0][0];
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row + col == 0) {
                    continue;
                }
                
                int ans = INT_MAX;
                if (row > 0) {
                    ans = min(ans, dp[row - 1][col]);
                }
                if (col > 0) {
                    ans = min(ans, dp[row][col - 1]);
                }
                
                dp[row][col] = grid[row][col] + ans;
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

*/