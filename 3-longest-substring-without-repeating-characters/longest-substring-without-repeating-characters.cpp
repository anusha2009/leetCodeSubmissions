class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> map;
        int res = 0;
        while(right < s.size()) {
            while(map[s[right]] >= 1) {
                map[s[left]]--;
                left++;
            }
            map[s[right]]++;
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};