class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap(piles.begin(), piles.end());
        for(int i=0;i<k;i++){
            int max = maxHeap.top();
            maxHeap.pop();
            max = ceil(max/2.0);
            maxHeap.push(max);

        }
        int total;
        while(!maxHeap.empty()) {
            total += maxHeap.top();
            maxHeap.pop();
        }
        return total;
        
    }
};