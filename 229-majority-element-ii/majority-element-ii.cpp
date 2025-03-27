class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> result;
        for(int num : nums) {
            map[num]++;
            if(map[num] > nums.size()/3 && find(result.begin(), result.end(), num) == result.end()) {
                result.push_back(num);
            }
        }
        return result;
    }
};