class Solution {
public:
    int solve(vector<int>& jd, int n, int idx, int d, vector<vector<int>>& dp) {

        // base case
        if (d == 1) {
            int maxD = jd[idx];

            for (int i = idx; i <= n - d; i++) {
                maxD = max(maxD, jd[i]);
            }

            return maxD;
        }

        // recursive case
        if (dp[idx][d] != -1)
            return dp[idx][d];

        int maxD = jd[idx];
        int finalResult = INT_MAX;

        for (int i = idx; i <= n - d; i++) {
            maxD = max(maxD, jd[i]);
            int curResult = maxD + solve(jd, n, i + 1, d - 1, dp);
            finalResult = min(finalResult, curResult);
        }

        return dp[idx][d] = finalResult;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        ios::sync_with_stdio(false);

        int n = jobDifficulty.size();
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));

        if (n < d)
            return -1;

        return solve(jobDifficulty, n, 0, d, dp);
    }
};