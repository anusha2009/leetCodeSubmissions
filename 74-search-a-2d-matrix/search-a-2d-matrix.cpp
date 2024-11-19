class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1, mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            int row = mid / n, col = mid % n;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
    
};