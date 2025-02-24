class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        for(int weight : weights) {
            right = right + weight;
            left = max(left, weight);
        }
        while(left<=right) {
            int mid = left + (right - left)/2;
            if(check(mid, weights, days)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool check(int mid, vector<int>& weights, int days) {
        int currSum = 0; 
        int daysNeeded = 0;
        for(int weight : weights) {
            currSum += weight;
            if(currSum>mid) {
                currSum = weight;
                daysNeeded++;
            }
        }
        return daysNeeded+1<=days;
    }
};