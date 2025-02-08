#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // If rowIndex=0, the row is just [1]
        // If rowIndex=1, the row is [1,1], etc.

        // Create a row of (rowIndex+1) elements, initialize to 1
        vector<int> row(rowIndex + 1, 1);

        // If rowIndex=0 or 1, we are effectively done, but the loop won't break anything
        // For i in [1..rowIndex-1], update from right to left
        for (int i = 1; i < rowIndex; i++) {
            // Update row[i] down to row[1]
            for (int j = i; j >= 1; j--) {
                row[j] += row[j - 1];
            }
        }
        
        return row;
    }
};
