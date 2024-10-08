class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() { ios::sync_with_stdio(false); }

    bool book(int start, int end) {
        auto it = st.upper_bound({start, end});
        cout<<it->first<<" "<< it->second<<" - ";
        if (it != st.end() && end > it->second) {
            return false;
        }

        st.insert({end, start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */