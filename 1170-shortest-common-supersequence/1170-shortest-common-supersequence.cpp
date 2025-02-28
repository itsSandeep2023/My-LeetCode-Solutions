class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        ios::sync_with_stdio(false);
               
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i{0}; i <= m; i++) {
            for (int j{0}; j <= n; j++) {
                if (i == 0 or j == 0)
                    dp[i][j] = i + j;
                else if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string ans;
        int i{m}, j{n};
        while (i > 0 and j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            } else {
                if (dp[i - 1][j] < dp[i][j - 1]) {
                    ans.push_back(str1[i - 1]);
                    i--;
                } else {
                    ans.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};