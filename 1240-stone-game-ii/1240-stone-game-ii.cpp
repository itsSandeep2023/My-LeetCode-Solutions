class Solution {
public:
    int n;
    int dp[2][101][101];

    int go(vector<int>& piles, int person, int i, int m) {
        if (i >= n)
            return 0;

        if (dp[person][i][m] != -1)
            return dp[person][i][m];

        int ans = person == 1 ? -1 : INT_MAX;

        int stones{0};

        for (int j{1}; j <= min(2 * m, n - i); j++) {
            stones += piles[i + j - 1];

            if (person == 1) {
                ans = max(ans, stones + go(piles, 0, i + j, max(m, j)));
            } else {
                ans = min(ans, go(piles, 1, i + j, max(m, j)));
            }
        }

        return dp[person][i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));

        return go(piles, 1, 0, 1);
    }
};