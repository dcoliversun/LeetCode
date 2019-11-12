class MyCalendar {
private:
    set<pair<int, int>> calendar;
public:
    MyCalendar() {
        calendar.insert({INT_MAX, INT_MAX});
        calendar.insert({INT_MIN, INT_MIN});
    }
    
    bool book(int start, int end) {
        auto next = calendar.lower_bound({start, end});
        if (next->first < end) return false;
        if ((--next)->second > start) return false;
        calendar.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
