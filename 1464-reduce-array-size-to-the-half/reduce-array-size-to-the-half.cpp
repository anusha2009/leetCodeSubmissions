class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        int size = n;
        unordered_map<int, int> map;
        priority_queue<int> maxHeap;
        for(int num : arr) {
            map[num]++;
        }
        for(auto& num : map) {
            maxHeap.push(num.second);
        }
        while(size>n/2) {
            int top = maxHeap.top();
            size = size - top;
            maxHeap.pop();
            result++;
        }
        return result;
        
        
    }
};