#include <vector>
#include <map>
#include <climits>
using namespace std;

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        // `space` stores checkpoints and their max reachable gaps.
        // Key: checkpoint position, Value: max distance to previous checkpoint
        map<int, int> space;
        space[0] = 0;
        space[INT_MAX] = INT_MAX;

        vector<bool> result;

        for (const auto& query : queries) {
            int type = query[0];
            int position = query[1];

            if (type == 1) {
                // Type 1: Add checkpoint at `position`
                // Insert the position into map with temporary value -1
                auto curr = space.emplace(position, -1).first;

                // Previous checkpoint
                auto prevIt = prev(curr);

                // Update gap distance from previous checkpoint
                curr->second = max(curr->first - prevIt->first, prevIt->second);

                // Update forward if needed
                auto nextIt = next(curr);
                while (nextIt != space.end()) {
                    int newGap = max(nextIt->first - curr->first, curr->second);
                    if (newGap == nextIt->second) break;
                    nextIt->second = newGap;
                    curr = nextIt;
                    ++nextIt;
                }

            } else {
                // Type 2: Check if position is within `maxJump` from a checkpoint
                int maxJump = query[2];

                // Find the checkpoint just before or equal to `position`
                auto it = prev(space.upper_bound(position));

                // Two conditions are sufficient:
                // 1. Is maxJump >= gap from its previous point?
                // 2. Is maxJump >= distance to this checkpoint?
                bool canReach = (it->second >= maxJump) || ((position - it->first) >= maxJump);
                result.push_back(canReach);
            }
        }

        return result;
    }
};
