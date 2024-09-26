class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //Find the first event that starts after or st the same time of {start, end}
        auto it = st.lower_bound({start, end}); //Log(N)

        //Check if the current event overlaps with the next event
        if(it != st.end() && it->first < end) {
            return false;
        }

        //Check if the current event overlaps with the previous event
        if(it != st.begin()) {
            auto prevIt = prev(it);
            if(start < prevIt->second) {
                return false;
            }
        }

        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */