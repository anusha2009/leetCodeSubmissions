class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        // Use hash set to record the status
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        map<pair<int, int>, unordered_set<char>> squares;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char val = board[r][c];
                // Check if the position is filled with number
                if (val == '.') {
                    continue;
                }
                // Check the row
                if (rows[r].find(val) != rows[r].end()) {
                    return false;
                }
                rows[r].insert(val);
                // Check the column
                if (cols[c].find(val) != cols[c].end()) {
                    return false;
                }
                cols[c].insert(val);
                // Check the box
                pair<int, int> squareKey = {r / 3, c / 3};
                if (squares[squareKey].count(val)) {
                    return false;
                }
                squares[squareKey].insert(val);
            }
        }
        return true;
    }
};