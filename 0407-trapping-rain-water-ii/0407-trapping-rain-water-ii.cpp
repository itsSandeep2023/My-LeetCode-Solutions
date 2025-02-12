class Solution {
#define pp pair<int, pair<int, int>>
public:
    int trapRainWater(vector<vector<int>>& hm) {
        int n = hm.size();
        int m = hm[0].size();

        priority_queue<pp, vector<pp>, greater<pp>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int r{0}; r < n; r++)
            for (int c : {0, m - 1}) {
                q.push({hm[r][c], {r, c}});
                vis[r][c] = true;
            }

        for (int c{1}; c < m - 1; c++)
            for (int r : {0, n - 1}) {
                q.push({hm[r][c], {r, c}});
                vis[r][c] = true;
            }

        int water{0};

        while (!q.empty()) {
            int height = q.top().first;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();

            for (int d{0}; d < 4; d++) {
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];

                if (ni >= 0 and ni < n and nj >= 0 and nj < m and
                    !vis[ni][nj]) {
                    water += max(height - hm[ni][nj], 0);
                    q.push({max(height, hm[ni][nj]), {ni, nj}});
                    vis[ni][nj] = true;
                }
            }
        }

        return water;
    }
};