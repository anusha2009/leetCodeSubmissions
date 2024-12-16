class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        
        // No need to sort, problem states input is sorted or we assume it.
        int start = nums[0];
        
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            // If next element is not consecutive
            if (nums[i] + 1 != nums[i+1]) {
                // Finalize current range
                if (nums[i] == start) {
                    // It's a single element range
                    result.push_back(to_string(start));
                } else {
                    // It's a multi-element range
                    result.push_back(to_string(start) + "->" + to_string(nums[i]));
                }
                // Start a new range from the next element
                start = nums[i+1];
            }
        }
        
        // After the loop, finalize the last range
        if (nums.back() == start) {
            result.push_back(to_string(start));
        } else {
            result.push_back(to_string(start) + "->" + to_string(nums.back()));
        }
        
        return result;
    }
};
