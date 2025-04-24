class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<vector<int>> adj;
        vector<bool> vis(graph.size(), false);
        vector<int> colour(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (!vis[i]) {
                if (!dfs(i, 0, vis, colour, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int node , int colourNode, vector<bool>& vis, vector<int>& colour, vector<vector<int>>& graph) {
        vis[node] = true;
        colour[node] = colourNode;
        for(auto edge : graph[node]) {
            if(!vis[edge]) {
                if (!dfs(edge, !colourNode, vis, colour, graph)) {
                    return false;
                }
            } else if(colour[edge] == colour[node]) {
                return false;
            }
        }
        return true;
    }
};