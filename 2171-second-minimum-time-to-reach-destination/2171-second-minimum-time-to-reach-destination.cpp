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
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, 1});
        d1[1] = 0;

        while (!q.empty()) {

            auto [timePassed, node] = q.top();
            q.pop();

            int div = timePassed / change;
            if (div % 2 == 1)
                timePassed = change * (div + 1);

            for (auto& nbr : adj[node]) {
                if (d1[nbr] > timePassed + time) {
                    d2[nbr] = d1[nbr];
                    d1[nbr] = timePassed + time;
                    q.push({timePassed + time, nbr});
                } else if (d2[nbr] > timePassed + time and
                           d1[nbr] != timePassed + time) {
                    d2[nbr] = timePassed + time;
                    q.push({timePassed + time, nbr});
                }

                if (d2[n] != INT_MAX)
                    return d2[n];
            }
        }

        return -1;
    }
};