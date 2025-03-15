// Define a pair of integers for simplicity
#define pi pair<int, int>

class Solution {
public:
    // Function to find minimum intervals for given queries
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals based on their start points
        sort(intervals.begin(), intervals.end());

        // Prepare pairs of queries with their indices for later retrieval
        vector<pair<int, int>> queryPair;
        for(int i = 0; i < queries.size(); i++) {
            queryPair.push_back({queries[i], i});
        }

        // Sort the query pairs based on their values
        sort(queryPair.begin(), queryPair.end());

        // Min-heap to store intervals' lengths in increasing order
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        // Result vector to store minimum intervals for each query
        vector<int> result(queryPair.size(), -1);

        // Pointer for iterating through intervals
        int j = 0;

        // Iterate through the sorted query pairs
        for(int i = 0; i < queryPair.size(); i++) {
            int query = queryPair[i].first;

            // Add intervals that start before or at the current query point
            while(j < intervals.size() && query >= intervals[j][0]) {
                pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                j++;
            }

            // Remove intervals that end before the current query point
            while(!pq.empty() && query > pq.top().second) {
                pq.pop();
            }

            // If there's a valid interval, update the result vector
            if(!pq.empty()) {
                result[queryPair[i].second] = pq.top().first;
            }
        }

        // Return the final result vector
        return result;
    }
};