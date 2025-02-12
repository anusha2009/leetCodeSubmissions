class Solution {
public:
    vector<bool> seen;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        seen = vector(n, false);
        seen[source] = true;
        return dfs(graph, source, destination);
    }
    bool dfs(unordered_map<int, vector<int>>& graph, int source, int destination) {
        if(source == destination) {
            return true;
        }
        for(auto& neighbour:graph[source]) {
            if(!seen[neighbour]) {
                seen[neighbour] = true;
                if(neighbour == destination) {
                    return true;
                }
                if(dfs(graph, neighbour, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
};