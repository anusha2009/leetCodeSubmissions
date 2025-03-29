class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int count = 0;
        int mod = 1e9 + 7;
        unordered_map<int, int> map;
        for(int i = 0; i<nums.size(); i++) {
            int value = nums[i] - rev(nums[i]);
            cout<<value<<'\n';
            if(map[value]>0) {
                count = (count + map[value]) % mod;
            }
            map[value]++;
        }
        return count;
    }
    int rev(int x) {
        int reverse = 0;
        while(x!=0) {
            int rem = x%10;
            x = x/10;
            reverse = reverse * 10 + rem;
        }
        return reverse;
    }
};