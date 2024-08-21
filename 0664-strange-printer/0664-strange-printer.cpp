class Solution {
public:
    vector<vector<int>> dp;

    int go(int l, int r, string s) {
        if (l == r)
            return 1;

        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int i = l + 1;

        while (i < r and s[i] == s[l]) {
            i++;

            if (i > r)
                return 1;
        }

        int ans = INT_MAX;

        for (int j{i}; j <= r; j++) {
            if (s[j] == s[l]) {
                int cans = go(i, j - 1, s) + go(j, r, s);

                ans = min(ans, cans);
            }
        }

        ans = min(ans, go(i, r, s) + 1);

        return dp[l][r] = ans;
    }

    int strangePrinter(string s) {
        int n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));

        return go(0, n - 1, s);
    }
};