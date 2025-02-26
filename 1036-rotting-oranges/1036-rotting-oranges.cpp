class Solution {
    #define P pair<int, int>
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

        queue<P> q;
        int cnt{0};
        for(int i{0}; i<n; i++)
        {
            for(int j{0}; j<m; j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    cnt++;
            }
        }
        
        int ans{0};
        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i{0}; i<4; i++)
                {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];

                    if(nr<n and nr>=0 and nc<m and nc>=0 and grid[nr][nc] == 1)
                    {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        cnt--;
                    }
                }
            }
            ans++;
        }

        if(cnt) return -1;

        return ans>1?ans-1:0;
    }
};