class Solution {
public:
    void dfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& vis, int& v, int& e)
    {
        vis[i] = true;
        v++;
        e+=adj[i].size();

        for(auto& nbr : adj[i])
        {
            if(!vis[nbr])
                dfs(nbr, adj, vis, v, e);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto& vec : edges)
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int ans{0};
        for(int i{0}; i<n; i++)
        {
            if(vis[i])
                continue;

            int v = 0;
            int e = 0;
            dfs(i, adj, vis, v, e);

            if(v*(v-1) == e)
                ans++;
        }

        return ans;
    }
};