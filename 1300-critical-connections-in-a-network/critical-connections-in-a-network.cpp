class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> rank;
    set<pair<int, int>> connSet;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        formGraph(n, connections);
        dfs(0, 0);

        vector<vector<int>> result;
        for (const auto& conn : connSet) {
            result.push_back({conn.first, conn.second});
        }
        return result;
    }

private:
    int dfs(int node, int discoveryRank) {
        if (rank.find(node) != rank.end()) {
            return rank[node];
        }

        rank[node] = discoveryRank;
        int minRank = discoveryRank + 1;

        for (int neighbor : graph[node]) {
            // Skip the parent
            if (rank.find(neighbor) != rank.end() && rank[neighbor] == discoveryRank - 1) {
                continue;
            }

            int recursiveRank = dfs(neighbor, discoveryRank + 1);

            if (recursiveRank <= discoveryRank) {
                int u = min(node, neighbor), v = max(node, neighbor);
                connSet.erase({u, v});
            }

            minRank = min(minRank, recursiveRank);
        }

        return minRank;
    }

    void formGraph(int n, vector<vector<int>>& connections) {
        for (int i = 0; i < n; i++) {
            graph[i] = vector<int>();
        }

        for (const auto& edge : connections) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);

            connSet.insert({min(u, v), max(u, v)});
        }
    }
};
