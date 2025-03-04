class Solution {
private:
    int log3(int a) { return log2(a) / log2(3); }

public:
    bool checkPowersOfThree(int n) {
        int t;
        unordered_set<int> st;
        while (n) {
            t = log3(n);
            if (st.count(t))
                return false;
            st.insert(t);
            n -= pow(3, t);
        }

        return true;
    }
};