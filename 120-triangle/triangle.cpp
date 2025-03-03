class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> triangle;
    int n;
    int m;
    int minimumTotal(vector<vector<int>>& triangle) {
        this->triangle = triangle;
        n = triangle.size();
        m = triangle[n-1].size();
        memo = vector(n, vector<int>(m, -1));
        return dp(0,0);
    }
    int dp(int i, int j) {
        if(i==n-1) {
            return triangle[i][j];
        }
        if(i>=n || j>=m) {
            return 0;
        }
        if(memo[i][j]!=-1) {
            return memo[i][j];
        }
        int ans = INT_MAX;
        ans = min(ans, dp(i+1, j));
        ans = min(ans, dp(i+1, j+1));
        memo[i][j] = triangle[i][j] + ans;
        return memo[i][j];

    }
};