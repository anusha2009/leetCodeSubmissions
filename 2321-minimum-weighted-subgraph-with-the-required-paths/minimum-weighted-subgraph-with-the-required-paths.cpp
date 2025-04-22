class Solution {
public:
    const long long INF = 1e15;

    vector<long long> dijkstra(int n, vector<vector<pair<int, int>>>& graph, int start) {
        vector<long long> dist(n, INF);
        dist[start] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> graph(n), revGraph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            revGraph[e[1]].push_back({e[0], e[2]});
        }

        auto dist1 = dijkstra(n, graph, src1);
        auto dist2 = dijkstra(n, graph, src2);
        auto toDest = dijkstra(n, revGraph, dest);

        long long ans = INF;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] < INF && dist2[i] < INF && toDest[i] < INF) {
                ans = min(ans, dist1[i] + dist2[i] + toDest[i]);
            }
        }

        return ans == INF ? -1 : ans;
    }
};
