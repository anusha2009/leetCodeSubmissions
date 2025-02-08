#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        // Edge case:
        if (numRows <= 0) {
            return result; // return empty for numRows=0 or negative
        }

        // The first row is always [1]
        result.push_back({1});

        // Build each subsequent row
        for (int i = 1; i < numRows; i++) {
            // Each row i has (i+1) elements, initialize them to 1
            vector<int> row(i + 1, 1);

            // Reference the previous row
            const vector<int>& prev = result[i - 1];

            // Fill the interior values using the sum of two adjacent values from 'prev'
            // Because the first and last elements remain 1, we start j at 1 and end at i-1
            for (int j = 1; j < i; j++) {
                row[j] = prev[j - 1] + prev[j];
            }

            // Add this newly built row to the result
            result.push_back(row);
        }

        return result;
    }
};
