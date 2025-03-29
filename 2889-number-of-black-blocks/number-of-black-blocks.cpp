class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        // Store all black cells in a set for fast lookup
        unordered_set<long long> blackSet;
        for (auto& coord : coordinates) {
            int x = coord[0], y = coord[1];
            blackSet.insert((long long)x * n + y);  // Encode as unique number
        }

        // Map: top-left corner of 2x2 block -> number of black cells in it
        unordered_map<long long, int> blockBlackCount;

        // Directions to find top-left corner of 2x2 blocks
        vector<pair<int,int>> dirs = {{0, 0}, {-1, 0}, {0, -1}, {-1, -1}};

        for (auto& coord : coordinates) {
            int x = coord[0], y = coord[1];
            for (auto& [dx, dy] : dirs) {
                int i = x + dx, j = y + dy;
                if (i >= 0 && i < m - 1 && j >= 0 && j < n - 1) {
                    long long key = (long long)i * n + j;
                    blockBlackCount[key]++;
                }
            }
        }

        // Answer: arr[i] = number of blocks with i black cells
        vector<long long> result(5, 0);

        for (auto& [key, blackCount] : blockBlackCount) {
            result[blackCount]++;
        }

        // Total possible 2x2 blocks = (m - 1) * (n - 1)
        long long totalBlocks = (long long)(m - 1) * (n - 1);
        result[0] = totalBlocks;

        // Subtract all the non-zero entries from result[0]
        for (int i = 1; i <= 4; i++) {
            result[0] -= result[i];
        }

        return result;
    }
};
