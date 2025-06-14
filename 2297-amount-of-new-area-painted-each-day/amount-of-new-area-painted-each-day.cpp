class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        set<pair<int, int>> painted;  // stores already painted intervals
        vector<int> result;

        for (auto& interval : paint) {
            int start = interval[0], end = interval[1];
            int newPaint = 0;
            auto it = painted.lower_bound({start, start}); // find first interval ≥ start

            // Step 1: check previous interval (could overlap)
            if (it != painted.begin()) {
                auto prev = std::prev(it);
                if (prev->second >= start) {
                    it = prev;
                }
            }

            // Step 2: iterate overlapping intervals
            vector<set<pair<int, int>>::iterator> toErase;
            int mergedStart = start, mergedEnd = end;

            while (it != painted.end() && it->first <= end) {
                // calculate unpainted area before this interval
                if (start < it->first) {
                    newPaint += it->first - start;
                }
                // update current merge window
                start = max(start, it->second);
                mergedStart = min(mergedStart, it->first);
                mergedEnd = max(mergedEnd, it->second);
                toErase.push_back(it++);
            }

            // If we still have unpainted part at the end
            if (start < end) {
                newPaint += end - start;
            }

            // Step 3: remove old intervals and insert merged one
            for (auto& e : toErase) {
                painted.erase(e);
            }
            painted.insert({mergedStart, mergedEnd});
            result.push_back(newPaint);
        }

        return result;
    }
};
