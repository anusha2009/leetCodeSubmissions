class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> map;
        int count = 0;
        for(int t : time) {
            int mod = t%60;
            if(map.find(60-mod) != map.end()) {
                count += map[60-mod];
            } else if(mod == 0 && map.find(0) != map.end()) {
                count += map[0];
            }
            map[mod]++;
        }
        return count;
    }
};