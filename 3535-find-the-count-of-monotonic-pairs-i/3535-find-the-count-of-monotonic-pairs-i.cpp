class Solution {
public:
    const int MOD = 1e9 + 7;

    int countMonotonicPairs(int i, int prevArr1, int prevArr2,
                            const vector<int>& nums,
                            vector<vector<vector<int>>>& dp) {
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
        int n = nums.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(51, vector<int>(51, -1)));

        return countMonotonicPairs(0, 0, 50, nums, dp);
    }
};