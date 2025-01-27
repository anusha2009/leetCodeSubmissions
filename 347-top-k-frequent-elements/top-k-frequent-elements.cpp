class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num: nums) {
            counts[num]++;
        }
        
        priority_queue<pair<int, int>> heap;
        for (auto [key, val]: counts) {
            heap.push({-val, key});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        vector<int> ans;
        while (heap.size() > 0) {
            ans.push_back(heap.top().second); heap.pop();
        }

        return ans;
    }
};