class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 1. Initialize two pointers i & j, start from 1 since no duplicate 
    // can exist for a single element
    int i = 1, j = 1;
    int duplicateCounter = 0;  // initialize duplicate counter
    
    // traverse array
    while (j < nums.size()) {
        // 2.1 update duplicateCounter upon encountering one or revert it back
        duplicateCounter = (nums[j] == nums[i - 1]) ? ++duplicateCounter : 0;
        
        // 2.2 only record nums[j] if duplicateCounter <= 1
        if (duplicateCounter <= 1) {
            nums[i++] = nums[j++];  // move i & j forwards
        }
        else {
            j++;  // otherwise, just move j to next position
        }
    }
    
    return i;  // pointer i at length of distinct array
    
    }
};