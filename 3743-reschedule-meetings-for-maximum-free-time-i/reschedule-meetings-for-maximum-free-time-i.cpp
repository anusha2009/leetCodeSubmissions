class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // calculate gap
        int n = startTime.size();
        vector<int>gap;

        if(startTime[0]>0)gap.push_back(startTime[0]-0);
        for(int i=1;i<n;i++){
            gap.push_back(startTime[i]-endTime[i-1]);
        }
        if(endTime[n-1]<eventTime)gap.push_back(eventTime-endTime[n-1]);

        // sliding window part starts
        int currSum=0;
        for(int i=0;i<=k && i<gap.size();i++){
            currSum+=gap[i];
        }
        int maxi = currSum;
        for(int i=k+1;i<gap.size();i++){
            currSum += gap[i];
            currSum -= gap[i-k-1];
            maxi = max(currSum,maxi);
        }

        return maxi;

    }
};