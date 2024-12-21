class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;

        vector<vector<vector<int>>> t(m, vector<vector<int>>(n, vector<int>(16, 0)));
        t[m - 1][n - 1][grid[m - 1][n - 1] ^ k] = 1;

        for (int i{m - 1}; i >= 0; i--) {
            for (int j{n - 1}; j >= 0; j--) {
                for (int curr = 0; curr < 16; curr++) {
                    int newCurr = curr ^ grid[i][j];

                    if (j + 1 < n) {
                        t[i][j][curr] =
                            (t[i][j][curr] + t[i][j + 1][newCurr]) % mod;
                    }

                    if (i + 1 < m) {
                        t[i][j][curr] =
                            (t[i][j][curr] + t[i + 1][j][newCurr]) % mod;
                    }
                }
            }
        }

        return t[0][0][0];
    }
};