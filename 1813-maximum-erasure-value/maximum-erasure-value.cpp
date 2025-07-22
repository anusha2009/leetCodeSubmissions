class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxScore = INT_MIN;
        int currScore = 0;
        int left = 0;
        unordered_set<int> seen;
        for(int right = 0; right<nums.size(); right++) {
            while(seen.find(nums[right]) != seen.end()) {
                seen.erase(nums[left]);
                currScore -= nums[left];
                left++;
            }
            currScore += nums[right];
            seen.insert(nums[right]);
            if(currScore > maxScore) {
                maxScore = currScore;
            }
        }
        return maxScore == INT_MIN ? -1 : maxScore;
    }
};