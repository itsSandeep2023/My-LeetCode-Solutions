class Solution {
public:
    int maxProductPath(vector<vector<int>>& gr) {
        int n = gr.size();
        int m = gr[0].size();
        vector<vector<long long int>> dp(n, vector<long long int>(m, 0));
        vector<vector<long long int>> mp(n, vector<long long int>(m, 0));
        dp[0][0] = gr[0][0];
        mp[0][0] = gr[0][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = gr[i][0] * dp[i - 1][0];
            mp[i][0] = gr[i][0] * mp[i - 1][0];
        }
        for (int j = 1; j < m; j++) {
            dp[0][j] = gr[0][j] * dp[0][j - 1];
            mp[0][j] = gr[0][j] * mp[0][j - 1];
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++) {
                if (gr[i][j] >= 0) {
                    dp[i][j] = max({(long long int)dp[i - 1][j] * gr[i][j],
                                    (long long int)dp[i][j - 1] * gr[i][j]});
                    mp[i][j] = min({(long long int)mp[i - 1][j] * gr[i][j],
                                    (long long int)mp[i][j - 1] * gr[i][j]});
                } else {
                    mp[i][j] = min({(long long int)dp[i - 1][j] * gr[i][j],
                                    (long long int)dp[i][j - 1] * gr[i][j]});
                    dp[i][j] = max({(long long int)mp[i - 1][j] * gr[i][j],
                                    (long long int)mp[i][j - 1] * gr[i][j]});
                }
            }

        return dp[n - 1][m - 1] < 0 ? -1 : dp[n - 1][m - 1] % 1000000007;
    }
};