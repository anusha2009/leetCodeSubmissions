class Solution {
public:
    vector<int> nums;
    int singleNonDuplicate(vector<int>& nums) {
        this->nums = nums;
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums[0] != nums[1]) {
            return nums[0];
        }
        if(nums[nums.size()-1] != nums[nums.size()-2]) {
            return nums[nums.size()-1];
        }
        int left = 0;
        int right = nums.size()-1;
        while(left<=right) {
            int mid = (left+right)/2;
            int valid = validCheck(mid);
            if(valid == 0) {
                return nums[mid];
            } else if((valid == 1 && mid%2 == 0) || (valid==2 && mid%2!=0)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            
        }
        return -1;
    }
    int validCheck(int mid) {
        int check = nums[mid];
        if(nums[mid-1] == check) {
            return 2;
        } else if(nums[mid+1] == check) {
            return 1;
        }
        return 0;
    }
};