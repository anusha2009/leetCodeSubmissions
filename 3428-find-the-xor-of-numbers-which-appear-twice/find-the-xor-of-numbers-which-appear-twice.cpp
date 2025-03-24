class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> set;
        int resultXor = 0;
        for(int num : nums) {
            if(find(set.begin(), set.end(), num) != set.end()) {
                resultXor ^= num;
            }
            set.insert(num);
        }
        return resultXor;
    }
};