class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--) {

            int maxi = INT_MIN;
            int ans = INT_MAX;
            int w = shelfWidth;

            for (int i = idx; i < n; i++) {
                maxi = max(maxi, books[i][1]);

                if (books[i][0] > w) {
                    break;
                }
                w -= books[i][0];
                int height = maxi + dp[i + 1];

                ans = min(ans, height);
            }

            dp[idx] = ans;
        }

        return dp[0];
    }
};