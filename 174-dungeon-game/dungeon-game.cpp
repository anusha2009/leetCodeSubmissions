class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> dungeon;
    int m, n;

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        this->dungeon = dungeon;
        m = dungeon.size();
        n = dungeon[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dp(0, 0);
    }

    int dp(int i, int j) {
        // Out of bounds, return large number so we can take min()
        if (i >= m || j >= n) return INT_MAX;

        // Base case: bottom-right (princess)
        if (i == m - 1 && j == n - 1) {
            return max(1, 1 - dungeon[i][j]);
        }

        // Already computed
        if (memo[i][j] != -1) return memo[i][j];

        int minHealthRight = dp(i, j + 1);
        int minHealthDown = dp(i + 1, j);
        int minNextHealth = min(minHealthRight, minHealthDown);

        // Calculate health needed at current cell
        int health = max(1, minNextHealth - dungeon[i][j]);

        return memo[i][j] = health;
    }
};
