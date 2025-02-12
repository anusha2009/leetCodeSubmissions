class Solution {
public:
    int WHITE = 1;
    int GRAY = 2;
    int BLACK = 3;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool isPossible = true;
        map<int, int> color;
        map<int, vector<int>> adjList;
        vector<int> topologicalOrder;

        // By default all vertices are WHITE.
        for (int i = 0; i < numCourses; i++) color[i] = WHITE;

        // Create the adjacency list representation of the graph.
        for (vector<int> relation : prerequisites) {
            int dest = relation[0];
            int src = relation[1];
            // if the key doesn't exist in the adjList, std::map will
            // automatically create a pair (key, vector()) and add it to the
            // map.
            adjList[src].push_back(dest);
        }

        // If the node is unprocessed, then call dfs on it.
        for (int i = 0; i < numCourses && isPossible; i++) {
            if (color[i] == WHITE) {
                dfs(i, color, adjList, isPossible, topologicalOrder);
            }
        }

        vector<int> order;
        if (isPossible) {
            order.resize(numCourses);
            for (int i = 0; i < numCourses; i++) {
                order[i] = topologicalOrder[numCourses - i - 1];
            }
        }
        return order;
    }

    void dfs(int node, map<int, int>& color, map<int, vector<int>>& adjList,
             bool& isPossible, vector<int>& topologicalOrder) {
        // Don't recurse further if we found a cycle already.
        if (!isPossible) return;

        // Start the recursion.
        color[node] = GRAY;

        // Traverse on neighboring vertices.
        for (int neighbor : adjList[node]) {
            if (color[neighbor] == WHITE) {
                dfs(neighbor, color, adjList, isPossible, topologicalOrder);
            } else if (color[neighbor] == GRAY) {
                // An edge to a GRAY vertex represents a cycle.
                isPossible = false;
            }
        }

        // Recursion ends. We mark it as black.
        color[node] = BLACK;
        topologicalOrder.push_back(node);
    }
};