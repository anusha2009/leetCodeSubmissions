class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
    // 1) Build the graph, storing 'to' airports in a multiset for each 'from'
        for (auto &t : tickets) {
            string from = t[0];
            string to = t[1];
            graph[from].insert(to);
        }

        // 2) DFS from "JFK" to build the path
        vector<string> result;
        dfs("JFK", result);

        // result will be in reverse postorder, so reverse at the end 
        reverse(result.begin(), result.end());
        return result;
    }

private:
    // adjacency: from -> multiset of to airports (sorted)
    map<string, multiset<string>> graph;

    // DFS function
    void dfs(const string &airport, vector<string> &result) {
        // while there are outgoing edges from 'airport'
        auto &neighbors = graph[airport];  // get the multiset of destinations
        while (!neighbors.empty()) {
            // pick the smallest next 'to'
            // multiset.begin() is the lexicographically smallest
            auto it = neighbors.begin(); 
            string nextAirport = *it;
            neighbors.erase(it); // remove this edge from the multiset
            dfs(nextAirport, result);
        }
        // once no more edges from 'airport', push airport in result (post-order)
        result.push_back(airport);
    }
};