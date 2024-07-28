class Solution {
public:
#define P pair<int, int>

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        ios::sync_with_stdio(false);

        unordered_map<int, vector<int>> adj;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> d1(n + 1, INT_MAX);
        vector<int> d2(n + 1, INT_MAX);
        queue<P> q;
        q.push({1, 1});
        d1[1] = 0;

        while (!q.empty()) {

            auto [node, freq] = q.front();
            q.pop();

            int timePassed = (freq == 1) ? d1[node] : d2[node];
            if (d2[n] != INT_MAX)
                return d2[n];

            int div = timePassed / change;
            if (div % 2 == 1)
                timePassed = change * (div + 1);

            for (auto& nbr : adj[node]) {
                if (d1[nbr] == INT_MAX) {
                    d1[nbr] = timePassed + time;
                    q.push({nbr, 1});
                } else if (d2[nbr] == INT_MAX and
                           d1[nbr] != timePassed + time) {
                    d2[nbr] = timePassed + time;
                    q.push({nbr, 2});
                }
            }
        }

        return -1;
    }
};