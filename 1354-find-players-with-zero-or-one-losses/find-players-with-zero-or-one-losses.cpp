class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer;
        vector<int> res1;
        vector<int> res2;
        unordered_map<int, int> map;
        for(auto& match : matches) {
            map[match[1]]++;
            if(map.find(match[0])!=map.end()) {
                continue;
            } else {
                map[match[0]] = 0;
            }
        }
        for(auto& m : map) {
            if(m.second == 0) {
                res1.push_back(m.first);
            }
            else if(m.second == 1) {
                res2.push_back(m.first);
            }
        }
        sort(res1.begin(), res1.end());
        sort(res2.begin(), res2.end());
        answer.push_back(res1);
        answer.push_back(res2);
        return answer;
    }
};