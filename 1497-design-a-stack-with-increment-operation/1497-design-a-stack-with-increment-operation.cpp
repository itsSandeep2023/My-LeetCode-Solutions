class CustomStack {
public:
    vector<int> st;
    vector<int> inc;
    int n;

    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(st.size() < n) {
            st.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() {
        if(st.empty()) {
            return -1;
        }

        int idx = st.size()-1;
        
        if(idx > 0) {
            inc[idx-1] += inc[idx];
        }

        int top_val = st[idx] + inc[idx];
        st.pop_back();
        inc.pop_back();
        
        return top_val;
    }
    
    void increment(int k, int val) {
        int idx = min(k, (int)st.size()) - 1;
        if (idx >= 0) {
            inc[idx] += val;
        }
    }
};