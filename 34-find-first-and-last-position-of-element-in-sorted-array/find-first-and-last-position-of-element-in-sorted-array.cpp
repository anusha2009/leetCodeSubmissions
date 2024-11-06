class Solution {
public:
    int BS(vector<int>& nums, int s, int e, int target) {
        int res = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                res = mid;
                e = mid - 1;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return res;
    }

    int BS1(vector<int>& nums, int s, int e, int target) {
        int res = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                res = mid;
                s = mid + 1;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int s = 0, e = nums.size();
        int mid = s + (e - s) / 2;

        int l = BS(nums, 0, nums.size() - 1, target);
        int r = BS1(nums, 0, nums.size() - 1, target);

        return {l, r};
    }
};