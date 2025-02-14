class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{0,1}, {1,0}, {0, -1}, {-1,0}};
        queue<vector<int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(rooms[i][j] == 0) {
                    q.push({i, j, 0});
                    seen[i][j] = true;
                }
            }
        }
        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int row = curr[0];
            int col = curr[1];
            int step = curr[2];
            for(auto& d : directions) {
                int newRow = row + d[0];
                int newCol = col + d[1];
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && !seen[newRow][newCol] && rooms[newRow][newCol] >= 0) {
                    q.push({newRow, newCol, step+1});
                    rooms[newRow][newCol] = step + 1;
                    seen[newRow][newCol] = true;
                }
            }
        }
    }
};