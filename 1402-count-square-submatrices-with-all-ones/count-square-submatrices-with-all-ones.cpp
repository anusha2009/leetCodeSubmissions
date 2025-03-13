class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> matrix;
    int m;
    int n;
    int countSquares(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        this->m = matrix.size();
        this->n = matrix[0].size();
        memo = vector(m, vector<int>(n, -1));
        int count = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                count += dp(i,j);
            }
        }
        return count;
    }
    int dp(int i, int j) {
        if(i>=m || j>=n) {
            return 0;
        }
        if(matrix[i][j]==0) {
            return 0;
        }
        if(memo[i][j]!=-1) {
            return memo[i][j];
        }
        int ans = INT_MAX;
        ans = min(ans, dp(i, j+1));
        ans = min(ans, dp(i+1, j));
        ans = min(ans, dp(i+1, j+1));
        memo[i][j] = ans + 1;
        return memo[i][j];
    }
};