class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        int n = rec.size();

        unordered_set<string> sups(sup.begin(), sup.end());
        unordered_map<string, vector<int>> adj;
        vector<int> ind(n);

        for(int i{0}; i<n; i++)
        {
            for(auto& x : ing[i])
            {
                if(!sups.count(x))
                {
                    adj[x].push_back(i);
                    ind[i]++;
                }
            }
        }

        queue<int> q;

        for(int i{0}; i<n; i++)
        {
            if(ind[i]==0)
                q.push(i);
        }

        vector<string> ans;

        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            ans.push_back(rec[i]);
            for(auto& x : adj[rec[i]])
            {
                ind[x]--;
                if(ind[x]==0)
                    q.push(x);
            }
        }

        return ans;
    }
};