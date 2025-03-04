class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> matrix;
    int m;
    int n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        this->m = matrix.size();
        this->n = matrix[0].size();
        memo = vector(m, vector<int>(n, -1));
        int maxPath = INT_MIN;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                maxPath = max(maxPath, dp(i, j));
            }
        }
        return maxPath;
    }
    int dp(int i, int j) {
        
        if(memo[i][j]!=-1) {
            return memo[i][j];
        }
        int ans = 0;
        if(j>=1 && matrix[i][j]<matrix[i][j-1]) {
            ans = max(ans, dp(i, j-1));
        } 
        if(j<n-1 && matrix[i][j]<matrix[i][j+1]) {
            ans = max(ans, dp(i, j+1));
        }
        if(i<m-1 && matrix[i][j]<matrix[i+1][j]) {
            ans = max(ans, dp(i+1, j));
        }
        if(i>=1 && matrix[i][j]<matrix[i-1][j]) {
            ans = max(ans, dp(i-1, j));
        }
        memo[i][j] = ans + 1;
        return memo[i][j];
    }
};