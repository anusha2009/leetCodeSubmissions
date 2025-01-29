class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = 0;
        for(int num: nums) {
            right = max(num, right);
        }
        while(left<=right) {
            double mid = (left + (right-left)/2)*1.0;
            if(check(mid, nums, threshold)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int check (double mid, vector<int>& nums, int threshold) {
        int sum = 0;
        for(int num : nums) {
            sum = sum + ceil(num/mid);
        }
        return sum <= threshold;
    }
};