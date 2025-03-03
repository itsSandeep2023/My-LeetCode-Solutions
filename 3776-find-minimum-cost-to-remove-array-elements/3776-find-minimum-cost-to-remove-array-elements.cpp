class Solution {
private:
    int n;

    int solve(int f, int s, vector<int>& nums, vector<vector<int>>& t) {
        if (s >= n)
            return nums[f];
        if (s == n - 1)
            return max(nums[f], nums[s]);

        if (t[f][s] != 0)
            return t[f][s];

        int op1 = max(nums[f], nums[s]) + solve(s + 1, s + 2, nums, t);
        int op2 = max(nums[f], nums[s + 1]) + solve(s, s + 2, nums, t);
        int op3 = max(nums[s], nums[s + 1]) + solve(f, s + 2, nums, t);

        return t[f][s] = min({op1, op2, op3});
    }

public:
    int minCost(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(n + 1));
        return solve(0, 1, nums, t);
    }
};