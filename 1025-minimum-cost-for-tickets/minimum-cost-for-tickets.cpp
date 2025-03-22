class Solution {
public:
    vector<int> memo;
    vector<int> days;
    vector<int> costs;

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        memo = vector<int>(days.size(), -1);
        return dp(0);
    }

    int dp(int i) {
        if (i >= days.size()) return 0;
        if (memo[i] != -1) return memo[i];

        // Option 1: 1-day pass
        int j = i;
        while (j < days.size() && days[j] < days[i] + 1) j++;
        int cost1 = costs[0] + dp(j);

        // Option 2: 7-day pass
        j = i;
        while (j < days.size() && days[j] < days[i] + 7) j++;
        int cost7 = costs[1] + dp(j);

        // Option 3: 30-day pass
        j = i;
        while (j < days.size() && days[j] < days[i] + 30) j++;
        int cost30 = costs[2] + dp(j);

        return memo[i] = min({cost1, cost7, cost30});
    }
};
