class Solution {
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
};