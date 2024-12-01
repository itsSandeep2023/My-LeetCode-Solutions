class Solution {
public:
    int dfs(vector<vector<int>>& g, int root, int parent, int k, int cnt = 1) {
        if (k < 0)
            return 0;
        for (auto node : g[root])
            cnt += (node != parent) ? dfs(g, node, root, k - 1) : 0;
        return cnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> g1(n);
        vector<vector<int>> g2(m);

        for (auto& e : edges1)
        {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2)
        {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }

        vector<int> ans;

        int cnt{0};
        for (int i{0}; i < m; i++)
            cnt = max(cnt, dfs(g2, i, -1, k - 1));
        for (int i{0}; i < n; i++)
            ans.push_back(cnt + dfs(g1, i, -1, k));

        return ans;
    }
};