class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> result(n, LLONG_MAX);
        int res = 0;
        int currWeight = 0;
        vector<int> map(n, 0);
        vector<pair<int, long long>> adj[n];
        for(auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        result[0] = 0;
        map[0] = 1;
        int mod = (int)(1e9 + 7);
        while(!pq.empty()) {
            pair<long long, int> curr = pq.top();
            pq.pop();
            long long weight = curr.first;
            int node = curr.second;
            if(weight>result[node]) {
                continue;
            }
            for(auto& edge : adj[node]) {
                long long newWeight = weight+edge.second + 0LL;;
                if(newWeight < result[edge.first]) {
                    map[edge.first] = map[node];
                    result[edge.first] = weight + edge.second;
                    pq.push({weight + edge.second, edge.first});
                } else if(weight+edge.second == result[edge.first]) {
                    map[edge.first] = (map[edge.first] + map[node])%mod;
                }
            }
        }
        return map[n-1];
    }
};