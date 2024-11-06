class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int low = 1, high = nums.size() - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        // Count how many numbers are less than or equal to mid
        for (int num : nums) {
            if (num <= mid) count++;
        }

        // Adjust search range based on count
        if (count > mid) {
            high = mid;  // Duplicate is in the lower half
        } else {
            low = mid + 1;  // Duplicate is in the upper half
        }
    }

    return low;  // low is the duplicate number
}
};