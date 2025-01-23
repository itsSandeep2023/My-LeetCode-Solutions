class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowCnt(n);
        vector<int> colCnt(m);

        for (int i{0}; i < n; i++) {
            for (int j{0}; j < m; j++) {
                rowCnt[i] += grid[i][j];
                colCnt[j] += grid[i][j];
            }
        }

        int ans{0};

        for (int i{0}; i < n; i++) {
            for (int j{0}; j < m; j++) {
                if (grid[i][j] and (rowCnt[i] > 1 or colCnt[j] > 1))
                    ans++;
            }
        }

        return ans;
    }
};