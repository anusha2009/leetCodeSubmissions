class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> results;
        for(int i = 0; i<equations.size(); i++) {
            double value = values[i];
            graph[equations[i][0]][equations[i][1]] = value;
            graph[equations[i][1]][equations[i][0]] = 1.0/value; 
        }
        for(int i = 0; i<queries.size(); i++) {
            if(graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end()) {
                results.push_back(-1.0);
            } else if(queries[i][0] == queries[i][1]) {
                results.push_back(1.0);
            } else {
                unordered_set<string> seen;
                double ans = dfs(graph, seen, queries[i][0], queries[i][1], 1.0);
                results.push_back(ans);
            }
        }
        return results;
        
    }
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& seen, string start, string end, double result) {
        if(start == end) {
            return result;
        }
        if(!seen.count(start)) {
            seen.insert(start);
            for(auto& neighbour : graph[start]) {
                if(!seen.count(neighbour.first)) {
                    double temp = dfs(graph, seen, neighbour.first, end, result * neighbour.second);
                    if(temp!=-1) {                 
                        return temp;
                    };
                }
            }
        }
        return -1;
    }
};