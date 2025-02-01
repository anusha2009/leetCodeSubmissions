class Solution {
public:
    int binarySearchLeft(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            int leftMostIndex = -1;
            while (left <= right) {
                int mid = left + (right - left)/2;
                if (nums[mid] > target) {
                    right = mid - 1;
                } else if (nums[mid] < target) {
                    left = mid + 1;    
                } else {
                    leftMostIndex = mid;
                    right = mid - 1;     
                }
            }
            return leftMostIndex;
}
    int binarySearchRight(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            int rightMostIndex = -1;
            
            while (left <= right) {
                int mid = left + (right - left)/2;
                if (nums[mid] > target) {
                    right = mid - 1;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    rightMostIndex = mid;
                    left = mid + 1;
                }
            }
            return rightMostIndex;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int l = binarySearchLeft(nums, target);
        int r = binarySearchRight(nums, target);

        return {l, r};
    }
};