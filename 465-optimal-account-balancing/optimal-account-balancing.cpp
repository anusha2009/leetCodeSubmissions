class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for (auto& t : transactions) {
            balance[t[0]] += t[2];
            balance[t[1]] -= t[2];
        }

        for (auto& [_, val] : balance) {
            if (val != 0) creditList.push_back(val);
        }

        int n = creditList.size();
        vector<int> memo(1 << n, -1);
        memo[0] = 0;
        return n - dfs((1 << n) - 1, memo);
    }

private:
    vector<int> creditList;

    int dfs(int mask, vector<int>& memo) {
        if (memo[mask] != -1) return memo[mask];

        int sum = 0, ans = 0;
        for (int i = 0; i < creditList.size(); ++i) {
            int bit = 1 << i;
            if (mask & bit) {
                sum += creditList[i];
                ans = max(ans, dfs(mask ^ bit, memo));
            }
        }

        memo[mask] = ans + (sum == 0 ? 1 : 0);
        return memo[mask];
    }
};
