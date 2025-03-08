#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;
        
        int target = totalSum / k;
        sort(nums.rbegin(), nums.rend()); // Sorting in descending order for pruning
        
        vector<int> buckets(k, 0);
        return backtrack(0, nums, buckets, target);
    }
    
    bool backtrack(int index, vector<int>& nums, vector<int>& buckets, int target) {
        if (index == nums.size()) return true;
        
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i] + nums[index] > target) continue; // Prune invalid states
            buckets[i] += nums[index];
            if (backtrack(index + 1, nums, buckets, target)) return true;
            buckets[i] -= nums[index]; // Backtrack
            
            if (buckets[i] == 0) break; // Avoid redundant checks
        }
        return false;
    }
};
