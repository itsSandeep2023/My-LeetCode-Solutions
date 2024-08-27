class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& probs, int start, int end) {
        ios::sync_with_stdio(false);
        
        unordered_map<int , vector<pair<int , double>>> adj;
        vector<double> ans(n, 0);
        ans[start] = 1;

        for(int i{0}; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v, probs[i]});
            adj[v].push_back({u, probs[i]});
        }

        priority_queue<pair<double, int>> q;
        q.push({1, start});

        while(!q.empty())
        {
            int node = q.top().second;
            double prob = q.top().first;

            q.pop();

            for(auto& nbr : adj[node])
            {
                int nbrNode = nbr.first;
                double nbrprob = nbr.second;

                if(ans[nbrNode] < nbrprob*prob)
                {
                    ans[nbrNode] = nbrprob*prob;
                    q.push({ans[nbrNode], nbrNode});
                }
            }
        }

        return ans[end];
    }
};