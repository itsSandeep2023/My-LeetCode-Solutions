class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> time(m, vector<int>(n, INT_MAX));
        time[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int curr_time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == m - 1 && col == n - 1)
                return curr_time;

            int dx[] = {0, -1, 0, 1};
            int dy[] = {-1, 0, 1, 0};

            for (int i = 0; i < 4; i++) {
                int nrow = dx[i] + row;
                int ncol = dy[i] + col;
                bool cond = (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n);

                if (cond) {
                    int diff = grid[nrow][ncol] - curr_time;
                    int new_time;
                    if (curr_time >= grid[nrow][ncol]) {
                        new_time = curr_time + 1;
                    } else if (diff % 2 == 1) {
                        new_time = grid[nrow][ncol];
                    } else {
                        new_time = grid[nrow][ncol] + 1;
                    }

                    if (time[nrow][ncol] > new_time) {
                        time[nrow][ncol] = new_time;
                        pq.push({new_time, {nrow, ncol}});
                    }
                }
            }
        }

        return -1; // never reach
    }
};