class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numSet(nums.begin(), nums.end());

        for (int i = 1; i <= n + 1; i++) {
            if (numSet.find(i) == numSet.end()) {
                return i; 
            }
        }

        return -1;
    }
};