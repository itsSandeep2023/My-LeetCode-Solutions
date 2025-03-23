class Solution {
    #define P pair<long long, int>
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& road : roads)
        {
            int u = road[0];
            int v = road[1];
            int time = road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> results(n, LLONG_MAX);
        vector<int> count(n);

        pq.push({0, 0});
        results[0] = 0;
        count[0] = 1;

        while(!pq.empty())
        {
            int currTime = pq.top().first;
            int currNode = pq.top().second;

            pq.pop();

            for(auto& node : adj[currNode])
            {
                int nbr = node.first;
                int roadTime = node.second;

                if(roadTime + currTime < results[nbr])
                {
                    results[nbr] = roadTime + currTime;
                    pq.push({results[nbr], nbr});
                    count[nbr] = count[currNode];
                }
                else if(roadTime + currTime == results[nbr])
                {
                    count[nbr] = (count[nbr] + count[currNode]) % MOD;
                }
            }
        }

        return count[n-1];
    }
};