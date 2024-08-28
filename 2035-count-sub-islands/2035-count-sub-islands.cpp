class Solution {
public:
    bool checkIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 or j < 0 or i >= grid1.size() or j >= grid1[0].size() or (grid2[i][j] != 1)) {
            return true;
        }

        grid2[i][j] = -1;

        bool ans = (grid1[i][j] == 1);

        ans = ans & checkIsland(grid1, grid2, i, j + 1);
        ans = ans & checkIsland(grid1, grid2, i, j - 1);
        ans = ans & checkIsland(grid1, grid2, i + 1, j);
        ans = ans & checkIsland(grid1, grid2, i - 1, j);

        return ans;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();

        int ans{0};

        for (int i{0}; i < m; i++) {
            for (int j{0}; j < n; j++) {
                if (grid2[i][j] == 1 and checkIsland(grid1, grid2, i, j)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};