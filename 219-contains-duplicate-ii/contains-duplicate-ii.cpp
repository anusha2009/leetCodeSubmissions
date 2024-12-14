#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen;  // Map to store the last index of each number
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end() && abs(i - seen[nums[i]]) <= k) {
                return true;  // Duplicate found within range
            }
            seen[nums[i]] = i;  // Update the last seen index of nums[i]
        }
        return false;  // No duplicate found within range
    }
};
