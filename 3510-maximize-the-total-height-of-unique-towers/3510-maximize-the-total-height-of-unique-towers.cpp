class Solution {
public:
    long long maximumTotalSum(vector<int>& mxh) {
        sort(mxh.begin(), mxh.end());
        int n = mxh.size();

        stack<pair<long long, long long>> st;

        if (mxh[0] > 1)
            st.push({0, mxh[0] - 1});

        long long ans = mxh[0];

        for (int i{1}; i < n; i++) {
            if (mxh[i] == mxh[i - 1]) {
                if (st.empty())
                    return -1;

                ans += st.top().second--;

                if (st.top().second <= st.top().first)
                    st.pop();
            } else {
                ans += mxh[i];
                if (mxh[i] - 1 > mxh[i - 1])
                    st.push({mxh[i - 1], mxh[i] - 1});
            }
        }

        return ans;
    }
};