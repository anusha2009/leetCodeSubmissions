#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return {};
        }
        
        int m = mat.size();
        int n = mat[0].size();
        
        // Total diagonals range from 0 to (m + n - 2)
        int totalDiags = m + n - 1;
        vector<int> result; 
        result.reserve(m * n); // optional, to avoid repeated reallocation
        
        for (int d = 0; d < totalDiags; d++) {
            // If d is even, we'll traverse from row down to 0
            // If d is odd, we'll traverse from 0 up to row
            // "row" + "col" = d.
            
            if (d % 2 == 0) {
                // d is even => go from bigger row to smaller row
                //   that means start row = min(d, m-1) down to max(0, d-(n-1))
                //   because col = d - row.
                
                int startRow = min(d, m - 1);
                int endRow = max(0, d - (n - 1));
                for (int r = startRow; r >= endRow; r--) {
                    int c = d - r;
                    result.push_back(mat[r][c]);
                }
            } else {
                // d is odd => go from smaller row to bigger row
                //   that means start row = max(0, d-(n-1)) up to min(d, m-1).
                
                int startRow = max(0, d - (n - 1));
                int endRow = min(d, m - 1);
                for (int r = startRow; r <= endRow; r++) {
                    int c = d - r;
                    result.push_back(mat[r][c]);
                }
            }
        }
        
        return result;
    }
};