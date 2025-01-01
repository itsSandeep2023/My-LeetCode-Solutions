class Solution {
    int n;
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int idx)
    {
        if(idx == n)
        {
            ans.push_back(nums);
            return;
        }

        solve(nums, ans, idx+1);

        for(int i{idx+1}; i<n; i++){
            swap(nums[idx], nums[i]);
            solve(nums, ans, idx+1);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }
};