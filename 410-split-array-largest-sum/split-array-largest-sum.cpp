class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while(left<=right) {
            int mid = left + (right - left)/2;
            if(check(mid, nums, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
        
    }

    bool check (int mid, vector<int>& nums, int k) {
        int curr = 0;
        int splits = 0;
        for(int num: nums) {
            if(curr + num <= mid) {
                curr += num;
            } else {
                curr = num;
                splits++;
            }
        }
        splits++;
        if(splits<= k) {
            return true;
        } 
        return false;

    }
};