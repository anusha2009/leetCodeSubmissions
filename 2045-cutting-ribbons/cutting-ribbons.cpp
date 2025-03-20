class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        // Binary search bounds
        int left = 0;
        int right = *max_element(ribbons.begin(), ribbons.end());

        // Perform binary search on the ribbon length
        while (left < right) {
            int middle = (left + right + 1) /
                         2;  // Use upper mid to prevent infinite loops
            if (isPossible(middle, ribbons, k)) {
                // If it's possible to make `k` pieces of length `middle`,
                // search the higher range
                left = middle;
            } else {
                // Otherwise, search the lower range
                right = middle - 1;
            }
        }
        return left;
    }

private:
    // Helper function to determine if it's possible to cut the ribbons into at
    // least `k` pieces of the given `x`
    bool isPossible(int x, vector<int>& ribbons, int k) {
        int totalRibbons = 0;
        for (int ribbon : ribbons) {
            // Number of pieces the current ribbon can contribute
            int pieces = ribbon / x;
            totalRibbons += pieces;
            // If the total reaches or exceeds `k`, we can stop early
            if (totalRibbons >= k) return true;
        }
        // It's not possible to make the cut
        return false;
    }
};