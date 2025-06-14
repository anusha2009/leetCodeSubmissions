class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
    map<int, int> paintedIntervals; // maps start -> end of already painted segments
    vector<int> result;

    for (auto& segment : paint) {
        int start = segment[0], end = segment[1];

        // Find the first painted interval that starts after `start`
        auto next = paintedIntervals.upper_bound(start);
        auto current = next;

        // Check if there's an overlapping interval before `start`
        if (current != paintedIntervals.begin()) {
            auto prevIt = prev(current);
            if (prevIt->second >= start) {
                // Extend current to include the overlapping one
                current = prevIt;
                start = current->second;
            } else {
                // No overlap, insert new interval
                current = paintedIntervals.insert({start, end}).first;
            }
        } else {
            // No previous interval, insert this as a new one
            current = paintedIntervals.insert({start, end}).first;
        }
        int newPaint = end - start;

        // Merge all overlapping future intervals and reduce painted area
        while (next != paintedIntervals.end() && next->first < end) {
            int overlapStart = next->first;
            int overlapEnd = next->second;
            newPaint -= min(end, overlapEnd) - overlapStart;
            end = max(end, overlapEnd);
            paintedIntervals.erase(next++);
        }

        // Update the merged interval
        current->second = max(current->second, end);
        result.push_back(max(0, newPaint));
    }

    return result;
}
};