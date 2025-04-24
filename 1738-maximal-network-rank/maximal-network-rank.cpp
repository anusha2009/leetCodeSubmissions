class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank = 0;
        unordered_map<int, unordered_set<int>> adj;
        // Construct adjency list 'adj', where adj[node] stores all nodes connected to 'node'.
        for (auto& road : roads) {
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }

        // Iterate on each possible pair of nodes.
        for (int node1 = 0; node1 < n; ++node1) {
            for (int node2 = node1 + 1; node2 < n; ++node2) {
                int currentRank = adj[node1].size() + adj[node2].size();
                if (adj[node1].find(node2) != adj[node1].end()) {
                    --currentRank;
                }
                // Find the current pair's respective network rank and store if it's maximum till now.
                maxRank = max(maxRank, currentRank);
            }
        }
        // Return the maximum network rank.
        return maxRank;
    }
};


/*class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(0));
        set<pair<int,int>> connect;
        int ans = 0;
        for(auto road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
            connect.insert({road[0], road[1]});
            connect.insert({road[1], road[0]});
        }
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                int rank = adj[i].size() + adj[j].size();
                if(connect.find({i, j}) != connect.end()) {
                    rank = rank - 1;
                }
                ans = max(ans, rank);
            }
        }
        return ans;
    }
};*/