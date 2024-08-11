class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& sts,
            int& goodNodes) {
        int st = 1;
        unordered_set<int> css;

        for (int neighbor : tree[node]) {
            if (neighbor == parent)
                continue;
            int child_size = dfs(neighbor, node, tree, sts, goodNodes);
            css.insert(child_size);
            st += child_size;
        }

        sts[node] = st;

        if (css.size() <= 1) {
            goodNodes++;
        }

        return st;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        
        int n = edges.size() + 1;
        vector<vector<int>> tree(n);
        vector<int> sts(n, 0);
        int goodNodes = 0;

        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, tree, sts, goodNodes);

        return goodNodes;
    }
};