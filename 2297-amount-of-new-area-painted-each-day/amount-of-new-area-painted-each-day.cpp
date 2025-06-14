class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        set<pair<int, int> > leftArea;
        leftArea.insert({ 0, 5e4 + 3 });
        vector<int> result(paint.size(), 0);
        
        for(int i = 0; i < paint.size(); i++) {
            auto lowerIt = leftArea.lower_bound({ paint[i][0], 0 });
            auto upperIt = leftArea.upper_bound({ paint[i][1], 1e9 });    
            if(lowerIt != leftArea.begin()) lowerIt--;
            vector<pair<int, int> > toDelete, toInsert;

            for(auto it = lowerIt; it != upperIt; it++) {
                if(it->second < paint[i][0] || it->first > paint[i][1]) continue;
                result[i] += min(paint[i][1], it->second) - max(paint[i][0], it->first);
                if(it->first < paint[i][0]) {
                    toInsert.push_back({ it->first, paint[i][0] });
                }
                if(it->second > paint[i][1]) {
                    toInsert.push_back({ paint[i][1], it->second });
                }
                toDelete.push_back(*it);
            }
            for(int j = 0; j < toDelete.size(); j++) leftArea.erase(toDelete[j]);
            for(int j = 0; j < toInsert.size(); j++) leftArea.insert(toInsert[j]);
        }
        return result;
    }
};