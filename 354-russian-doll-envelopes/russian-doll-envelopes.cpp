#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }
        return dp.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort: increasing width, decreasing height if width is the same
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] == b[0]) ? (b[1] < a[1]) : (a[0] < b[0]);
        });

        // Extract the second dimension (heights)
        vector<int> secondDim;
        for (const auto& envelope : envelopes) {
            secondDim.push_back(envelope[1]);
        }

        // Run LIS on heights
        return lengthOfLIS(secondDim);
    }
};