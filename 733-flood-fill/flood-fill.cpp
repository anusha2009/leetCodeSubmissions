class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<vector<int>> q;
        q.push({sr, sc, image[sr][sc]});
        vector<vector<int>> seen(m, vector<int>(n, 0));
        vector<vector<int>> directions{{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int row = curr[0];
            int col = curr[1];
            int currColour = curr[2];
            seen[row][col] = 1;
            image[row][col] = color;
            for(auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && image[newRow][newCol]==currColour && !seen[newRow][newCol]) {
                    q.push({newRow, newCol, image[newRow][newCol]});
                }
            }
        }
        return image;
    }
};