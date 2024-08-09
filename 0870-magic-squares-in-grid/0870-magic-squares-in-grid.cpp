class Solution {
public:
    bool checkGrid(vector<vector<int>>& grid, int r, int c) {

        //  check distinct
        unordered_set<int> st;
        for (int i{-1}; i <= 1; i++) {
            for (int j{-1}; j <= 1; j++) {
                int num = grid[r + i][c + j];
                if (num < 1 or num > 9 or st.count(num))
                    return false;
                st.insert(num);
            }
        }

        // rows check
        int sum = grid[r - 1][c - 1] + grid[r - 1][c] + grid[r - 1][c + 1];

        if (sum != grid[r][c - 1] + grid[r][c] + grid[r][c + 1] or
            sum != grid[r + 1][c - 1] + grid[r + 1][c] + grid[r + 1][c + 1])
            return false;

        //  cols check

        if (sum != grid[r - 1][c - 1] + grid[r][c - 1] + grid[r + 1][c - 1] or
            sum != grid[r - 1][c] + grid[r][c] + grid[r + 1][c] or
            sum != grid[r - 1][c + 1] + grid[r][c + 1] + grid[r + 1][c + 1])
            return false;

        // diagonals check
        if (sum != grid[r - 1][c - 1] + grid[r][c] + grid[r + 1][c + 1] or
            sum != grid[r - 1][c + 1] + grid[r][c] + grid[r + 1][c - 1])
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // ios::sync_with_stdio(false);

        int ans{0};

        for (int i{1}; i < grid.size() - 1; i++) {
            for (int j{1}; j < grid[0].size() - 1; j++) {
                if (checkGrid(grid, i, j))
                    ans++;
            }
        }

        return ans;
    }
};