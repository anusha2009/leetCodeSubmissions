class Solution {
public:
    int n;
    
    int totalNQueens(int n) {
        this->n = n;
        unordered_set<int> diagonals;
        unordered_set<int> antiDiagonals;
        unordered_set<int> cols;
        return backtrack(0, diagonals, antiDiagonals, cols);
    }
    
    int backtrack(int row, unordered_set<int>& diagonals, unordered_set<int>& antiDiagonals, unordered_set<int>& cols) {
        // Base case - N queens have been placed
        if (row == n) {
            return 1;
        }
        
        int solutions = 0;
        for (int col = 0; col < n; col++) {
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            
            // If the queen is not placeable
            if (cols.find(col) != cols.end() ||
               diagonals.find(currDiagonal) != diagonals.end() ||
               antiDiagonals.find(currAntiDiagonal) != antiDiagonals.end()) {
                continue;
            }
            
            // "Add" the queen to the board
            cols.insert(col);
            diagonals.insert(currDiagonal);
            antiDiagonals.insert(currAntiDiagonal);
            
            // Move on to the next row with the updated board state
            solutions += backtrack(row + 1, diagonals, antiDiagonals, cols);
            
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.erase(col);
            diagonals.erase(currDiagonal);
            antiDiagonals.erase(currAntiDiagonal);
        }
        
        return solutions;
    }
};