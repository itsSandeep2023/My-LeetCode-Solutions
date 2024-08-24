class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& tree, int& goodNodes) {
        int st = 1;
        unordered_set<int> css;

        for (int neighbor : tree[node]) {
            if (neighbor == parent)
                continue;
            int child_size = dfs(neighbor, node, tree, goodNodes);
            css.insert(child_size);
            st += child_size;
        }

        if (css.size() <= 1) {
            goodNodes++;
        }

        return st;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n = edges.size() + 1;
        vector<vector<int>> tree(n);
        int goodNodes = 0;

        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, tree, goodNodes);

        return goodNodes;
    }
};