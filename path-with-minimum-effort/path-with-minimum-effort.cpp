class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        result[0][0] = 0;
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int weight = curr[0];
            int r = curr[1];
            int c = curr[2];
            if(weight>result[r][c]) {
                continue;
            }
            if(r==n-1 && c==m-1) {
                return weight;
            }
            for(auto& d : dir) {
                int newRow = r + d[0];
                int newCol = c + d[1];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m) {
                    int cost = abs(heights[newRow][newCol] - heights[r][c]);
                    if(max(cost, weight)<result[newRow][newCol]) {
                        result[newRow][newCol] = max(cost, weight);
                        pq.push({max(cost, weight), newRow, newCol});
                    }
                    
                }
            }
        }
        return result[n-1][m-1] == INT_MAX? 0:result[n-1][m-1];
    }
};