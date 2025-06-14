class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        set<pair<int, int>> painted;
        vector<int> result;

        for (auto& p : paint) {
            int start = p[0], end = p[1];
            int newPaint = 0;

            auto it = painted.lower_bound({start, 0});
            if (it != painted.begin()) {
                --it;
                if (it->second <= start) ++it;  // skip non-overlapping left
            }

            // Merge overlapping intervals
            vector<pair<int, int>> toErase;
            int curr = start;
            while (it != painted.end() && it->first < end) {
                if (it->first > curr) {
                    newPaint += it->first - curr;
                }
                curr = max(curr, it->second);
                toErase.push_back(*it);
                ++it;
            }

            if (curr < end) {
                newPaint += end - curr;
            }

            // Remove old intervals
            for (auto& e : toErase) painted.erase(e);

            // Insert merged interval
            int mergedStart = start;
            int mergedEnd = end;
            if (!toErase.empty()) {
                mergedStart = min(start, toErase.front().first);
                mergedEnd = max(end, toErase.back().second);
            }
            painted.insert({mergedStart, mergedEnd});

            result.push_back(newPaint);
        }

        return result;
    }
};
