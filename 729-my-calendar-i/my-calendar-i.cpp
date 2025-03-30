class MyCalendar {
public:
    vector<vector<int>> interval;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(int i = 0; i<interval.size(); i++) {
            if(startTime < interval[i][1] && interval[i][0] < endTime) {
                return false;
            } 
        }
        interval.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */