class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        ROWS = board.size();
        COLS = board[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1)
                    DFS(board, i, j);
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
    }

private:
    int ROWS, COLS;
    void DFS(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') return;
        board[i][j] = 'E';
        if (j < COLS - 1) DFS(board, i, j + 1);
        if (i < ROWS - 1) DFS(board, i + 1, j);
        if (j > 0) DFS(board, i, j - 1);
        if (i > 0) DFS(board, i - 1, j);
    }
};