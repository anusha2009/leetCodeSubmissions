class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort the meetings by starting time. 
        // we start by creating rooms for the meetings and putting them in a heap
        // minHeap of their finish times.
        // whenever a new meeting is seen, we check the top of the heap, if
        // it is supposed to be finished before this meeting starts, then we can
        // occupy the same room. In that case, just let that meeting finish (pop the
        // heap min) and insert this meeting.
        // If the earliest finishing meeting is after this meeting could start, we 
        // need a new room. In that case, when we add another meeting, we check the
        // number of rooms currently required.
        sort(intervals.begin(), intervals.end()) ;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto v : intervals) {
            // check if the last meetings need to be completed
            // before this meeting starts.
            if (!pq.empty() && pq.top() <= v[0]) {
                pq.pop();
            }
            
            // start this meeting and enter the end time.
            pq.push(v[1]);
        }
        
        return pq.size();
    }
};