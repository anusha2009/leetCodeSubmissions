class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> mergedMeetings;
        int count = 0;
        for(auto meeting : meetings) {
            if(mergedMeetings.empty() || mergedMeetings.back()[1] < meeting[0]) {
                mergedMeetings.push_back(meeting);
            } else {
                mergedMeetings.back()[1] = max(mergedMeetings.back()[1], meeting[1]);
            }
        }
        count += mergedMeetings[0][0] - 1;
        for(int i = 0; i<mergedMeetings.size()-1; i++) {
            count += mergedMeetings[i+1][0] - mergedMeetings[i][1] - 1;
        }
        count += days - mergedMeetings[mergedMeetings.size()-1][1];
        return count;
    }
};