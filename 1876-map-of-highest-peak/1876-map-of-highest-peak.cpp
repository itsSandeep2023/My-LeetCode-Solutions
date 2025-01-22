class Solution {
#define P pair<int, int>
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        queue<P> q;

        for (int i{0}; i < n; i++) {
            for (int j{0}; j < m; j++) {
                if (isWater[i][j] == 1)
                    q.push({i, j});
            }
        }

        int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int level = 1;
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [i, j] = q.front();
                q.pop();

                for (int k{0}; k < 4; k++) {
                    int ni = i + d[k][0];
                    int nj = j + d[k][1];

                    if (ni >= 0 and ni < n and nj >= 0 and nj < m and
                        isWater[ni][nj] == 0) {
                        q.push({ni, nj});
                        ans[ni][nj] = level;
                        isWater[ni][nj] = 1;
                    }
                }
            }
            level++;
        }

        return ans;
    }
};