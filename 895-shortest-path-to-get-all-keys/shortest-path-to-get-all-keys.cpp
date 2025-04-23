class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int allKeys = 0, startRow = 0, startCol = 0;

        // 1. Preprocess: find total number of keys and starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '@') {
                    startRow = i;
                    startCol = j;
                } else if (islower(c)) {
                    allKeys |= (1 << (c - 'a')); // bitmask with all keys
                }
            }
        }

        // 2. BFS: state = (row, col, keys)
        queue<tuple<int, int, int>> q;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(64, false)));
        q.push({startRow, startCol, 0});
        visited[startRow][startCol][0] = true;

        int steps = 0;
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c, keys] = q.front();
                q.pop();

                if (keys == allKeys) return steps;

                for (auto [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    int newKeys = keys;

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    char ch = grid[nr][nc];
                    if (ch == '#') continue;

                    // Lock: ensure we have the key
                    if (isupper(ch) && !(keys & (1 << (ch - 'A')))) continue;

                    // Key: collect it
                    if (islower(ch)) {
                        newKeys |= (1 << (ch - 'a'));
                    }

                    if (!visited[nr][nc][newKeys]) {
                        visited[nr][nc][newKeys] = true;
                        q.push({nr, nc, newKeys});
                    }
                }
            }
            steps++;
        }

        return -1; // unreachable
    }
};
