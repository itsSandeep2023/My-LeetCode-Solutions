class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis)
    {
        if(i<0 or i>=m or j<0 or j>=n or vis[i][j] or grid[i][j]==0)
            return;

        vis[i][j] = 1;

        dfs(grid, i+1,j,vis);
        dfs(grid, i-1,j,vis);
        dfs(grid, i,j+1,vis);
        dfs(grid, i,j-1,vis);
    }

    int numberOfIslands(vector<vector<int>>& grid)
    {
        int islands{0};

        vector<vector<bool>> vis(m, vector<bool>(n));

        for(int i{0};i<m;i++)
        {
            for(int j{0};j<n;j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    dfs(grid, i, j, vis);
                    islands++;
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int islands = numberOfIslands(grid);
        if(islands>1 or islands == 0)
            return 0;

        for(int i{0};i<m;i++)
        {
            for(int j{0};j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;

                    islands = numberOfIslands(grid);

                    if(islands>1 or islands == 0)
                        return 0;

                    grid[i][j] = 1;  
                }
            }
        }

        return 2;
    }
};