class Solution {
public:
    double maxProbability(int n,
                          vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node,
                          int end_node)
    {
        // 1) Build adjacency as a vector of vectors of (neighbor, probability)
        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < (int)edges.size(); i++) {
            int source = edges[i][0];
            int dest   = edges[i][1];
            double prob = succProb[i]; // store as double
            adj[source].push_back({dest, prob});
            adj[dest].push_back({source, prob});
        }

        // 2) We'll keep a max-heap for (prob, node)
        // And result[node] = best probability to reach node so far
        vector<double> result(n, 0.0);
        result[start_node] = 1.0;

        // max-heap, so we store (prob, node) and use a 'less' comparator
        // we can do that by making the pair<double,int> negative or use a custom comparator
        // but a simpler approach: we'll store (prob, node) and rely on standard behavior by flipping sign or using greater<...>
        // We'll do: priority_queue< pair<double,int> > where we want largest 'double' first => default is max-heap
        priority_queue<pair<double,int>> pq;

        // Start from (1.0, start_node)
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [currProb, node] = pq.top();
            pq.pop();

            

            // If we've reached end_node, we can return right away
            if (node == end_node) {
                return currProb;
            }

            // Explore neighbors
            for (auto &edge : adj[node]) {
                int nxt = edge.first;
                double w = edge.second;
                double newProb = currProb * w;
                // If we can improve the prob for 'nxt'
                if (newProb > result[nxt]) {
                    result[nxt] = newProb;
                    pq.push({newProb, nxt});
                }
            }
        }

        // If we never update end_node, return 0.0
        return 0.0;
    }
};
