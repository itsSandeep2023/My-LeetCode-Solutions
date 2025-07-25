class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;

        int ans = *max_element(nums.begin(), nums.end());

        if (ans <= 0)
            return ans;

        ans = 0;

        for (int& x : nums) {
            if (x > 0 && !st.count(x)) {
                ans += x;
                st.insert(x);
            }
        }

        return ans;
    }
};