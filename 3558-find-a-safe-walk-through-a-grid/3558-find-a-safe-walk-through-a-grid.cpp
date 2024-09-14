class Solution {
public:


    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        queue<tuple<int, int, int>> q;
        q.push({0, 0, health-grid[0][0]});

        vector<vector<int>> vis(m, vector<int>(n, -1));
        vis[0][0] = health;

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();
            cout<<h<<" ";
            if (r == m - 1 and c == n - 1 and h > 0) {
                return true;
            }

            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nh = h - grid[nr][nc];

                    if (nh > 0 && nh > vis[nr][nc]) {
                        vis[nr][nc] = nh;
                        q.push({nr, nc, nh});
                    }
                }
            }
        }

        return false;
    }
};