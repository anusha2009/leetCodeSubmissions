class Solution {
public:

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<pair<string, double>>> graph1, graph2;

        // Build Day 1 graph (including reverse edges)
        for (int i = 0; i < pairs1.size(); ++i) {
            graph1[pairs1[i][0]].emplace_back(pairs1[i][1], rates1[i]);
            graph1[pairs1[i][1]].emplace_back(pairs1[i][0], 1.0 / rates1[i]);
        }

        // Build Day 2 graph (including reverse edges)
        for (int i = 0; i < pairs2.size(); ++i) {
            graph2[pairs2[i][0]].emplace_back(pairs2[i][1], rates2[i]);
            graph2[pairs2[i][1]].emplace_back(pairs2[i][0], 1.0 / rates2[i]);
        }

        // Day 1 BFS
        unordered_map<string, double> day1Amount;
        queue<pair<string, double>> q;
        q.emplace(initialCurrency, 1.0);
        day1Amount[initialCurrency] = 1.0;

        while (!q.empty()) {
            auto [curr, val] = q.front(); q.pop();
            for (auto& [next, rate] : graph1[curr]) {
                double newVal = val * rate;
                if (newVal > day1Amount[next]) {
                    day1Amount[next] = newVal;
                    q.emplace(next, newVal);
                }
            }
        }

        // Day 2 BFS starting from all currencies we reached on Day 1
        unordered_map<string, double> day2Amount = day1Amount;
        queue<pair<string, double>> q2;
        for (auto& [cur, val] : day1Amount) {
            q2.emplace(cur, val);
        }

        while (!q2.empty()) {
            auto [curr, val] = q2.front(); q2.pop();
            for (auto& [next, rate] : graph2[curr]) {
                double newVal = val * rate;
                if (newVal > day2Amount[next]) {
                    day2Amount[next] = newVal;
                    q2.emplace(next, newVal);
                }
            }
        }

        return day2Amount[initialCurrency]; // final value in original currency
    }
};