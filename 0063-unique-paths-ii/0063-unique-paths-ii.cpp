class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n = obs.size();
        int m = obs[0].size();

        if(obs[n-1][m-1] == 1) return 0;

        vector<vector<long long>> t(n, vector<long long>(m));
        t[n - 1][m - 1] = 1;

        for (int i{n - 2}; i >= 0; i--) {
            if (obs[i][m - 1] == 1)
                break;
            t[i][m - 1] = 1;
        }

        for (int i{m - 2}; i >= 0; i--) {
            if (obs[n - 1][i] == 1)
                break;
            t[n - 1][i] = 1;
        }

        for (int i{n - 2}; i >= 0; i--) {
            for (int j{m - 2}; j >= 0; j--) {
                if (obs[i][j] == 1)
                    continue;

                t[i][j] = t[i + 1][j] + t[i][j + 1];
            }
        }

        return t[0][0];
    }
};