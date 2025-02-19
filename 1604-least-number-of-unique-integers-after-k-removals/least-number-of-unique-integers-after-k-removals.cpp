class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int x : arr) {
            map[x]++;
        } 
        for(auto& m : map) {
            minHeap.push({m.second, m.first});
        }
        while(k>0 && !minHeap.empty()) {
            pair<int, int> top = minHeap.top();
            if(top.first!=1) {
                top.first--;
                minHeap.pop();
                minHeap.push(top);
            } else {
                minHeap.pop();
            }
            cout<<top.first<<top.second<<'\n';
            k--;
        }
        return minHeap.size();
    }
};