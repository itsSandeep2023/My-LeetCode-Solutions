class Solution {
public:
    int S;
    int solve(vector<int>& nums, int &target, int i, int sum, vector<vector<int>>& t) {
        if(i == nums.size()) {
            return sum == target ? 1 : 0;
        }

        if(t[i][sum+S] != INT_MIN) {
            return t[i][sum+S];
        }
        int plus  = solve(nums, target, i+1, sum+nums[i], t);
        int minus = solve(nums, target, i+1, sum-nums[i], t);

        return t[i][sum+S] = plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        S = accumulate(begin(nums), end(nums), 0);
        vector<vector<int>> t(n, vector<int>(2*S+1, INT_MIN));
        return solve(nums, target, 0, 0, t);
    }
};
