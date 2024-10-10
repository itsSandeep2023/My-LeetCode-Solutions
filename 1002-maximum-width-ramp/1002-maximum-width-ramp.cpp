class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        int n = nums.size();
        stack<int> st;

        st.push(0);

        for (int i = 1; i < n; i++) {
            if (nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int ans = 0;
        int i = n - 1;
        while (!st.empty() and i > 0) {

            while (!st.empty() and nums[st.top()] <= nums[i]) {
                ans = max(ans, i - st.top());
                st.pop();
            }

            i--;
        }

        return ans;
    }
};