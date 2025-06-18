class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        map<int, int> space = {{0, 0}, {INT_MAX, INT_MAX}};
        vector<bool> result;
        for (auto& q : queries) {
            if (q[0] == 1) {
                auto c = space.emplace(q[1], -1).first;
                auto p = prev(c);
                do {
                    c->second = max(c->first - p->first, p->second);
                    p = c++;
                } while (c != space.end() && c->second != p->second);
            } else {
                auto it = prev(space.upper_bound(q[1]));
                result.push_back(it->second >= q[2] || q[1] - it->first >= q[2]);
            }
        }
        return result;
    }
};