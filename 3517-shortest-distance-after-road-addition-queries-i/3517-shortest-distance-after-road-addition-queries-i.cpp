class Solution {
public:
    int bfs(int& n, unordered_map<int, vector<int>>& adj) {
        vector<int> distance(n, -1);
        queue<int> q;

        q.push(0);
        distance[0] = 0;

        while (!q.empty()) {
            int city = q.front();
            q.pop();
            int currDist = distance[city];

            for (int neighbor : adj[city]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = currDist + 1;
                    q.push(neighbor);

                    if (neighbor == n - 1) {
                        return distance[n - 1];
                    }
                }
            }
        }

        return distance[n - 1];
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (int i{0}; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> ans;
        for (const auto& vec : queries) {
            adj[vec[0]].push_back(vec[1]);

            ans.push_back(bfs(n, adj));
        }

        return ans;
    }
};