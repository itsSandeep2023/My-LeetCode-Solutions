class Solution {
#define P pair<int, int>
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int maxFish{0};

        for (int i{0}; i < m; i++) {
            for (int j{0}; j < n; j++) {
                if (grid[i][j] > 0 and !vis[i][j]) {
                    queue<P> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    int curFish{0};

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        curFish += grid[r][c];

                        for (int k{0}; k < 4; k++) {
                            int nr = r + dir[k][0];
                            int nc = c + dir[k][1];

                            if (nr >= 0 and nr < m and nc >= 0 and nc < n and
                                !vis[nr][nc] and grid[nr][nc] > 0) {
                                q.push({nr, nc});
                                vis[nr][nc] = true;
                            }
                        }
                    }

                    maxFish = max(maxFish, curFish);
                }
            }
        }

        return maxFish;
    }
};