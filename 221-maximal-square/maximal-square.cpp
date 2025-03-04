class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<char>> matrix;
    int m;
    int n;
    int maximalSquare(vector<vector<char>>& matrix) {
        this->matrix = matrix;
        this->m = matrix.size();
        this->n = matrix[0].size();
        memo = vector(m, vector<int>(n, -1));
        int maxValue = INT_MIN;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                maxValue = max(maxValue, dp(i,j));
            }
        }
        return maxValue*maxValue;
    }
    int dp(int i, int j) {
        if(i>=m || j>=n) {
            return 0;
        }
        if(matrix[i][j]=='0') {
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