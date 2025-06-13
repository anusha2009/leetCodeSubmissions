class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
       vector<vector<int>> dir = {{0,-1}, {0,1}, {1,0}, {-1,0}};
       int m = maze.size();
       int n = maze[0].size();
       queue<vector<int>> q;
       vector<vector<bool>> vis(m, vector<bool>(n, false));
       q.push(start);
       vis[start[0]][start[1]] = true;
       while(!q.empty()) {
        vector<int> curr = q.front();
        int row = curr[0];
        int col = curr[1];
        if(row == destination[0] && col == destination[1]) {
            return true;
        }
        q.pop();
        for(auto d : dir) {
            int newRow = row + d[0];
            int newCol = col + d[1];
            while(newRow>=0 && newRow<m && newCol >=0 && newCol<n && maze[newRow][newCol] != 1) {
                newRow += d[0];
                newCol += d[1];
            }
            newRow -= d[0];
            newCol -= d[1];
            if(!vis[newRow][newCol]) {
                vis[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
       }
       return false;
    }
};