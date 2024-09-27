class MyCalendar {
    set<pair<int, int>> st;

public:
    MyCalendar() { ios::sync_with_stdio(false); }

    bool book(int start, int end) {
        for (pair<int, int> curr : st)
            if (max(curr.first, start) < min(curr.second, end))
                return false;

        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */