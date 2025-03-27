class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> map;
        int left = 0, count = 0;
        
        for (int right = 0; right < s.size(); right++) {
            map[s[right]]++;
            
            // shrink window while it's valid (contains a, b, c)
            while (map['a'] > 0 && map['b'] > 0 && map['c'] > 0) {
                count += s.size() - right;  // all substrings from [left, right] to end are valid
                map[s[left]]--;
                left++;
            }
        }
        
        return count;
    }
};
