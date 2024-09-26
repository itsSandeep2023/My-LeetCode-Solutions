#define P pair<int, int>
class MyCalendar {
public:
    
    vector<P> calendar;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        for(int i = 0; i<calendar.size(); i++) {
            P curr = calendar[i];
            if(!(end <= curr.first || start >= curr.second))
                return false;
        }
        
        calendar.push_back({start, end});
        return true;
    }
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */