class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<bool> seen(n, false);
        for(auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        for(int i=0;i<n;i++) {
            if(!seen[i]) {
                count++;
                dfs(i, graph, seen);
            }
        }
        return count;
        
    }
    void dfs(int source, unordered_map<int, vector<int>>& graph, vector<bool>& seen) {
            seen[source] = true;
            for(auto& neighbour : graph[source]) {
                if(!seen[neighbour]) {
                    dfs(neighbour, graph, seen);
                }
            }
    }
};