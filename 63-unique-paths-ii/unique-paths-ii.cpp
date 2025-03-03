class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> obstacleGrid;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->obstacleGrid = obstacleGrid;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memo = vector(m, vector<int>(n, -1));
        return dp(m-1, n-1);
    }
    int dp(int row, int col) {
        if(obstacleGrid[row][col]==1) {
            return 0;
        }
        if(row+col==0) {
            return 1;
        }
        if(memo[row][col]!=-1) {
            return memo[row][col];
        }
        int ways = 0;
        if(row>0) {
            ways += dp(row-1, col);
        }
        if(col>0) {
            ways += dp(row, col-1);
        }
        memo[row][col] = ways;
        return ways;
    }
};