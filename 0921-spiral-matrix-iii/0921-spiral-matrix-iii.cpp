class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>> ans;

        int steps{0};
        int dir{0};

        ans.push_back({rStart, cStart});

        while (ans.size() < rows * cols) {
            if (dir == 0 or dir == 2)
            {
                steps++;
            }

            for (int i{0}; i < steps; i++) {
                rStart += dirs[dir][0];
                cStart += dirs[dir][1];

                if (rStart < rows and rStart >= 0 and cStart < cols and
                    cStart >= 0) {
                    ans.push_back({rStart, cStart});
                }
            }

            dir = (dir + 1) % 4;
        }

        return ans;
    }
};