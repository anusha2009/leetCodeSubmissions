class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        int max_weight = 5000;
        int curr_weight = 0;
        int num_of_baskets = 0;
        priority_queue<int,vector<int>,greater<int>> minHeap (weight.begin(), weight.end());
        while(!minHeap.empty()){
            if(curr_weight+minHeap.top()<=max_weight){
                curr_weight+= minHeap.top(); minHeap.pop();
                num_of_baskets++;
            }
            else return num_of_baskets;
        }
        return num_of_baskets;
    }
};