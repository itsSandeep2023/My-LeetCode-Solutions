class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefixX(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> prefixY(n + 1, vector<int>(m + 1, 0));

        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prefixX[i][j] = prefixX[i - 1][j] + prefixX[i][j - 1] -
                                prefixX[i - 1][j - 1] +
                                (grid[i - 1][j - 1] == 'X' ? 1 : 0);
                prefixY[i][j] = prefixY[i - 1][j] + prefixY[i][j - 1] -
                                prefixY[i - 1][j - 1] +
                                (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
                if (prefixX[i][j] > 0 and prefixX[i][j] == prefixY[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};