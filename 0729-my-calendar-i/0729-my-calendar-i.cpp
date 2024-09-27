class MyCalendar {
    set<pair<int, int>> overallBookings;

public:
    MyCalendar() { ios::sync_with_stdio(false); }

    bool checkOverlap(int first, int second, int start, int end) {
        return max(first, start) < min(second, end);
    }

    bool book(int start, int end) {
        for (pair<int, int> region : overallBookings)
            if (checkOverlap(region.first, region.second, start, end))
                return false;

        overallBookings.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */