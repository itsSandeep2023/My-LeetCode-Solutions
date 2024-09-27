class MyCalendarTwo {
    vector<pair<int, int>> doubleOverlappedRegion;
    vector<pair<int, int>> overallBookings;

public:
    MyCalendarTwo() {}

    bool checkOverlap(int first, int second, int start, int end) {
        return max(first, start) < min(second, end);
    }

    pair<int, int> findOverlappedRegion(int first, int second, int start,
                                        int end) {
        return {max(first, start), min(second, end)};
    }

    bool book(int start, int end) {
        // check tripplet
        for (pair<int, int> region : doubleOverlappedRegion)
            if (checkOverlap(region.first, region.second, start, end))
                return false;

        // check double and create
        for (pair<int, int> booking : overallBookings)
            if (checkOverlap(booking.first, booking.second, start, end))
                doubleOverlappedRegion.push_back(findOverlappedRegion(
                    booking.first, booking.second, start, end));

        overallBookings.push_back({start, end});
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */