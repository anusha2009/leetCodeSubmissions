class Solution {
public:
    set<vector<int>> roads;
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    
    int minReorder(int n, vector<vector<int>>& connections) {
        seen = vector(n, false);
        for (vector<int> edge: connections) {
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
            roads.insert({x, y});
        }
        
        seen[0] = true;
        return dfs(0);
    }
    
    int dfs(int node) {
        int ans = 0;
        for (int neighbor: graph[node]) {
            if (!seen[neighbor]) {
                if (roads.find({node, neighbor}) != roads.end()) {
                    ans++;
                }
                
                seen[neighbor] = true;
                ans += dfs(neighbor);
            }
        }
        
        return ans;
    }
};