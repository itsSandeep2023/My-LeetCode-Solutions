class Solution {
public:

    int countMonotonicPairs(int i, int prevArr1, int prevArr2, const vector<int>& nums, vector<vector<vector<int>>>& dp) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        if (i == n)
            return 1;

        if (dp[i][prevArr1][prevArr2] != -1)
            return dp[i][prevArr1][prevArr2];

        int totalCount = 0;

        for (int arr1_i = prevArr1; arr1_i <= nums[i]; ++arr1_i) {
            int arr2_i = nums[i] - arr1_i;

            if (arr2_i <= prevArr2) {
                totalCount =
                    (totalCount +
                     countMonotonicPairs(i + 1, arr1_i, arr2_i, nums, dp)) %
                    MOD;
            }
        }

        return dp[i][prevArr1][prevArr2] = totalCount;
    }

    int countOfPairs(vector<int>& nums) {
        ios::sync_with_stdio(false);

        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end()) + 1;

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));

        return countMonotonicPairs(0, 0, m - 1, nums, dp);
    }
};