class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> minHeap(nums.begin(), nums.end());
        int count = 0;
        cout<<minHeap.top()<<'\n';
        if(minHeap.top()>=k) {
            return count;
        }
        while(minHeap.top()<k && minHeap.size()>=2) {
            long x = minHeap.top();
            minHeap.pop();
            long y = minHeap.top();
            minHeap.pop();
            long sum = min(x,y)*2+max(x,y);
            minHeap.push(sum);
            count++;
        }
        return count;
    }
};