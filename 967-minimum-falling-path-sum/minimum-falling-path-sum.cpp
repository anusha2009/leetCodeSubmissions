class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minFallingSum = INT_MAX;
        vector<vector<optional<int>>> memo(
            matrix.size(), vector<optional<int>>(matrix.size(), nullopt));

        // start a DFS (with memoization) from each cell in the top row
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, findMinFallingPathSum(
                                                   matrix, 0, startCol, memo));
        }
        return minFallingSum;
    }

    int findMinFallingPathSum(vector<vector<int>>& matrix, int row, int col,
                              vector<vector<optional<int>>>& memo) {
        // base cases
        if (col < 0 || col == matrix.size()) {
            return INT_MAX;
        }
        // check if we have reached the last row
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }
        // check if the results are calculated before
        if (memo[row][col] != nullopt) {
            return (memo[row][col]).value_or(0);
        }

        // calculate the minimum falling path sum starting from each possible
        // next step
        int left = findMinFallingPathSum(matrix, row + 1, col - 1, memo);
        int middle = findMinFallingPathSum(matrix, row + 1, col, memo);
        int right = findMinFallingPathSum(matrix, row + 1, col + 1, memo);

        int minSum = min(left, min(middle, right)) + matrix[row][col];

        memo[row][col] = minSum;
        return minSum;
    }
};
