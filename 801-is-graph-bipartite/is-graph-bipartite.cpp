class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 means uncolored

        for (int start = 0; start < n; ++start) {
            if (color[start] == -1) {
                queue<int> q;
                q.push(start);
                color[start] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false; // Same color on both sides -> not bipartite
                        }
                    }
                }
            }
        }

        return true;
    }
};

//DFS
/*class Solution {
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
};*/