class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // Step 1: Apply gravity to each row
        for (int i = 0; i < m; ++i) {
            int write = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    write = j - 1; // Reset write pointer after obstacle
                } else if (box[i][j] == '#') {
                    if (write != j) {
                        swap(box[i][write], box[i][j]);
                    }
                    write--;
                }
            }
        }

        // Step 2: Rotate the matrix 90 degrees clockwise
        vector<vector<char>> result(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[j][m - 1 - i] = box[i][j];
            }
        }

        return result;
    }
};
