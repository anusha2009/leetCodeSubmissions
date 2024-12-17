class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m * n);
        int j = 0;
        int l = 0, u = 0, d = m - 1, r = n - 1;
        
        while (l <= r && u <= d) {
            
            // Traverse from left to right
            if (l <= r && u <= d) {
                for (int i = l; i <= r; i++) {
                    res[j++] = matrix[u][i];
                }
                u++;
            }
            
            // Traverse from top to bottom
            if (l <= r && u <= d) {
                for (int i = u; i <= d; i++) {
                    res[j++] = matrix[i][r];
                }
                r--;
            }
            
            // Traverse from right to left
            if (l <= r && u <= d) {
                for (int i = r; i >= l; i--) {
                    res[j++] = matrix[d][i];
                }
                d--;
            }
            
            // Traverse from bottom to top
            if (l <= r && u <= d) {
                for (int i = d; i >= u; i--) {
                    res[j++] = matrix[i][l];
                }
                l++;
            }
        }
        
        return res;
    }
};