class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ios::sync_with_stdio(false);
        
        int n = positions.size();

        vector<int> a_idx(n);
        iota(a_idx.begin(), a_idx.end(), 0);

        sort(a_idx.begin(), a_idx.end(),
             [&](int& i, int& j) { return positions[i] < positions[j]; });

        vector<int> ans;
        stack<int> st;

        for (int& c_idx : a_idx) {
            if (directions[c_idx] == 'R') {
                st.push(c_idx);
            } else {
                while (!st.empty()) {
                    int top_idx = st.top();

                    if (healths[top_idx] < healths[c_idx]) {
                        healths[c_idx] -= 1;
                        healths[top_idx] = 0;
                        st.pop();
                        continue;
                    }

                    if (healths[top_idx] > healths[c_idx]) {
                        healths[top_idx] -= 1;
                        healths[c_idx] = 0;
                    } else {
                        healths[top_idx] = 0;
                        healths[c_idx] = 0;
                        st.pop();
                    }

                    break;
                }
            }
        }

        for (int& x : healths) {
            if (x > 0)
                ans.push_back(x);
        }

        return ans;
    }
};