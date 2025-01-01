class Solution {
    int n;
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int idx) {
        if (idx == n) {
            ans.push_back(nums);
            return;
        }

        solve(nums, ans, idx + 1);
        unordered_set<int> st;
        st.insert(nums[idx]);

        for (int i{idx + 1}; i < n; i++) {
            if(!st.count(nums[i]))
            {
                swap(nums[idx], nums[i]);
                solve(nums, ans, idx + 1);
                swap(nums[idx], nums[i]);
                st.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        n = nums.size();
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }
};