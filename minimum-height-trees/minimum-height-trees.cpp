class Solution {
    public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Edge case: if there is 0 or 1 node, return all nodes
        if(n < 2) {
            vector<int> centroids;
            for(int i = 0; i < n; i++) {
                centroids.push_back(i);
            }
            return centroids;
        }
        
        // Build the graph using an adjacency list of unordered_set<int>
        vector<unordered_set<int>> neighbors(n);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            neighbors[u].insert(v);
            neighbors[v].insert(u);
        }
        
        // Initialize the first layer of leaves (nodes with only one neighbor)
        vector<int> leaves;
        for(int i = 0; i < n; i++) {
            if(neighbors[i].size() == 1)
                leaves.push_back(i);
        }
        
        // Trim the leaves until there are at most 2 nodes remaining
        int remainingNodes = n;
        while(remainingNodes > 2) {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            for(int leaf : leaves) {
                // Each leaf has exactly one neighbor
                int neighbor = *(neighbors[leaf].begin());
                // Remove the leaf from its neighbor's set
                neighbors[neighbor].erase(leaf);
                if(neighbors[neighbor].size() == 1)
                    newLeaves.push_back(neighbor);
            }
            leaves = newLeaves;
        }
        
        // The remaining nodes are the centroids
        return leaves;
    }    
    
};