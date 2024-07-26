class Solution {
public:
    #define P pair<int, int>

    void dijkstra(int n,  unordered_map<int, vector<P>> & adj, vector<int>& result, int s)
    {
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, s});

        while(!q.empty())
        {
            int d = q.top().first;
            int node = q.top().second;
            q.pop();

            for(auto& p: adj[node])
            {
                int nbr = p.first;
                int dist = p.second;

                if(d + dist < result[nbr])
                {
                    result[nbr] = d+dist;
                    q.push({d+dist, nbr});
                }
            } 
        }
    }

    int findResultCity(int n,  vector<vector<int>>& SPM, int d)
    {
        int result = -1;
        int smallest = 1e9+7;

        for(int i{0};i<n;i++)
        {
            int curr{0};
            for(int j{0};j<n;j++)
            {
                if(i!=j and SPM[i][j] <= d)
                {
                    curr++;
                }
            }

            if(curr<=smallest)
            {
                smallest = curr;
                result = i;
            }
        }

        return result;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n, vector<int>(n, 1e9+7));

        for(int i {0};i<n;i++)
        {
            SPM[i][i] = 0;
        }

        unordered_map<int, vector<P>> adj;
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        for(int i{0};i<n;i++)
        {
            dijkstra(n, adj, SPM[i], i);
        }

        return findResultCity(n, SPM, distanceThreshold);
    }
};