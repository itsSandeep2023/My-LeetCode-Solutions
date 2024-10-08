class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        ios::sync_with_stdio(false);
        
        priority_queue<int> pq;
        vector<int> ans;

        for (const auto& query : queries) {
            int x = query[0];
            int y = query[1];
            int dist = abs(x) + abs(y);

            pq.push(dist);

            if (pq.size() > k) {
                pq.pop();
            }

            if (pq.size() < k) {
                ans.push_back(-1);
            } else {
                ans.push_back(pq.top());
            }
        }

        return ans;
    }
};