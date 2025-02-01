class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();  // Get the size of the array
        int s = 0;             // Initialize the start pointer
        int e = n - 1;         // Initialize the end pointer

        // Perform binary search
        while (s < e) {
            int mid = s + (e - s) / 2;  // Calculate the middle index to prevent overflow

            // Check if mid is a peak element:
            // 1. Either it's the first element or greater than the previous element
            // 2. Either it's the last element or greater than the next element
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && 
                (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;  // Found a peak, return its index
            }

            // If the element to the right of mid is greater, move the start pointer
            if (mid < n - 1 && nums[mid + 1] > nums[mid]) {
                s = mid + 1;
            }
            // Otherwise, move the end pointer to mid - 1
            else {
                e = mid - 1;
            }
        }

        // Return the start pointer which will be at the peak when s == e
        return s;
    }
};