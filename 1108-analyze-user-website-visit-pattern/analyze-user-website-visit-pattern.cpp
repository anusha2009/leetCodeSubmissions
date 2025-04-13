class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        vector<tuple<int, string, string>> logs;
        for (int i = 0; i < n; ++i) {
            logs.emplace_back(timestamp[i], username[i], website[i]);
        }
        sort(logs.begin(), logs.end());

        unordered_map<string, vector<string>> userWebsites;
        for (auto& [time, user, site] : logs) {
            userWebsites[user].push_back(site);
        }

        map<vector<string>, unordered_set<string>> patternUsers;
        for (auto& [user, sites] : userWebsites) {
            int sz = sites.size();
            set<vector<string>> seen;
            for (int i = 0; i < sz; ++i) {
                for (int j = i + 1; j < sz; ++j) {
                    for (int k = j + 1; k < sz; ++k) {
                        vector<string> pattern = {sites[i], sites[j], sites[k]};
                        if (seen.insert(pattern).second) {
                            patternUsers[pattern].insert(user);
                        }
                    }
                }
            }
        }

        int maxScore = 0;
        vector<string> result;
        for (auto& [pattern, users] : patternUsers) {
            if ((int)users.size() > maxScore || ((int)users.size() == maxScore && pattern < result)) {
                maxScore = users.size();
                result = pattern;
            }
        }
        return result;
    }
};